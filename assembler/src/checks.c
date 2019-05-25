/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:05:50 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/03 19:05:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void	check_label(char *line, char **admit, t_all *info)
{
	int		i;
	char	*dop;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	if (line[i] == LABEL_CHAR)
	{
		info->number_tokens += 1;
		while (line[i] && !ft_isalnum(line[i]))
			i++;
		dop = ft_strsub(line, i, ft_strlen(line));
		(*admit) = dop;
		free(dop);
	}
	else
		(*admit) = line;
}

void	count_token_instr(char *admit, t_all *info)
{
	int i;

	i = -1;
	while (++i < NUMB_INSTRUCTION)
	{
		if (ft_strcmp(admit, g_op[i].instruction) == 0)
		{
			info->number_tokens += g_op[i].number_arg + 1;
			break ;
		}
	}
}

void	check_line(t_file *file, t_all *info)
{
	char	*admit;
	char	*rest;

	if (ft_strncmp(file->line, NAME_CMD_STRING, 5) == 0 ||
		(info->is_name == 0 && info->quote == 1))
		get_name_and_comment(file, info, 1);
	else if (ft_strncmp(file->line, COMMENT_CMD_STRING, 8) == 0 || \
	(info->is_comment == 0 && info->quote == 1))
		get_name_and_comment(file, info, 2);
	else if (info->is_name == 1 && info->is_comment == 1)
	{
		check_label(file->line, &admit, info);
		cut_instruction(&admit, &rest, file->count_lines);
		count_token_instr(admit, info);
		free(admit);
		free(rest);
	}
	else
		print_err(10, file->count_lines, NULL);
}

int		is_labelchars(char *line, int end)
{
	int i;
	int j;
	int identical;

	i = -1;
	identical = 0;
	while (line[++i] && i <= end)
	{
		j = -1;
		if (end == identical)
			return (1);
		while (LABEL_CHARS[++j])
		{
			if (LABEL_CHARS[j] == line[i])
			{
				identical++;
				break ;
			}
		}
	}
	return (0);
}
