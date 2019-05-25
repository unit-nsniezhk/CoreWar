/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:03:37 by amartyne          #+#    #+#             */
/*   Updated: 2019/04/22 14:03:38 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

unsigned int	check_digit(char *line)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(line))
		if (!ft_isdigit(line[i]))
			print_err(9, 0, NULL);
	return (ft_atoi(line));
}

int				find_instructions(char *instr)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if (!ft_strcmp(instr, g_op[i].instruction))
			return (i);
	}
	return (20);
}

void			cut_label(char *line, char **admit, t_all *info)
{
	int		i;
	char	*dop;

	i = 0;
	while ((line[i] && ft_isalnum(line[i])) || line[i] == '_')
		i++;
	if (line[i] == LABEL_CHAR && is_labelchars(line, i))
	{
		info->tokens[info->n].value = 0;
		info->tokens[info->n].name = ft_strsub(line, 0, i);
		info->tokens[info->n++].token = LABEL;
		while (line[i] && !ft_isalnum(line[i]))
			i++;
		dop = ft_strsub(line, i, ft_strlen(line));
		(*admit) = dop;
		free(dop);
	}
	else
		(*admit) = line;
}

int				cut_instruction(char **line, char **rest, int n)
{
	int		i;
	int		j;
	int		commas;
	char	*admit;
	char	*tmp;

	tmp = ft_strtrim(*line);
	commas = count_symbols(*line, ',');
	i = 0;
	while (ft_isalpha(tmp[i]))
		i++;
	(admit) = ft_strsub(tmp, 0, i);
	(*rest) = ft_strsub(tmp, (i + 1), ft_strlen(tmp));
	j = find_instructions(admit);
	if (ft_strlen(tmp) && (i <= 0 || j > 16))
		print_err(8, n, NULL);
	else if (ft_strlen(tmp) && commas != g_op[j].args_commas)
		print_err(7, n, NULL);
	*line = admit;
	free(tmp);
	return (1);
}
