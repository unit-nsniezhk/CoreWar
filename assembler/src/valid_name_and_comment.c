/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:03:25 by ychufist          #+#    #+#             */
/*   Updated: 2019/05/16 14:20:53 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

int		check_around_quote(char *line, int key)
{
	int i;

	i = 0;
	if (key == 1 || key == 3)
	{
		if (line[i] != '"')
			return (0);
	}
	if (key == 2 || key == 3)
	{
		if (line[ft_strlen(line) - 1] != '"')
			return (0);
	}
	return (1);
}

int		get_get(int key, t_all *info, char *dop)
{
	if (key == 1)
	{
		info->champion_name = ft_strsub(dop, 1, ft_strlen(dop) - 2);
		if (ft_strlen(info->champion_name) > PROG_NAME_LENGTH ||
		info->is_name == 1)
			error_in_name_and_comment(key, 1);
		info->is_name = 1;
	}
	if (key == 2)
	{
		info->comment = ft_strsub(dop, 1, ft_strlen(dop) - 2);
		if (ft_strlen(info->comment) > COMMENT_LENGTH ||
			info->is_comment == 1)
			error_in_name_and_comment(key, 2);
		info->is_comment = 1;
	}
	ft_strdel(&info->tmp);
	return (1);
}

void	if_quotes(t_all *info, char *dop, char *tmp, t_point i_q)
{
	char *jury;

	if (i_q.x == 1 && info->quote == 0 && check_around_quote(dop, 1))
	{
		info->tmp = ft_strchr(dop, '"');
		jury = ft_strcat(info->tmp, "\n");
		info->tmp = ft_strdup(jury);
		info->quote = 1;
	}
	else if (i_q.x == 0 && info->quote == 1)
	{
		tmp = ft_strjoin(info->tmp, ft_strcat(tmp, "\n"));
		free(info->tmp);
		info->tmp = ft_strdup(tmp);
		free(tmp);
	}
	else if (i_q.x == 1 && info->quote == 1 && check_around_quote(dop, 2))
	{
		tmp = ft_strjoin(info->tmp, dop);
		info->quote = 0;
		get_get(i_q.y, info, tmp);
		free(tmp);
	}
	free(dop);
}

void	get_name_and_comment(t_file *file, t_all *info, int key)
{
	int		i;
	t_point	quotes;
	char	*tmp;
	char	*dop;

	i = (key == 1) ? 5 : 8;
	tmp = (info->quote == 0) ? ft_strsub(file->line, i,
			ft_strlen(file->line) - i) : file->line;
	dop = (info->quote == 1) ? ft_strtrim_dop(tmp, 2) : ft_strtrim_dop(tmp, 1);
	if (info->quote == 0)
		free(tmp);
	quotes.x = count_symbols(dop, '"');
	quotes.y = key;
	if (quotes.x == 2 && info->quote == 0 && check_around_quote(dop, 3))
	{
		get_get(key, info, dop);
		free(dop);
	}
	else if ((quotes.x == 1 && info->quote == 0) || (quotes.x == 0 &&
			info->quote == 1) || (quotes.x == 1 && info->quote == 1))
		if_quotes(info, dop, tmp, quotes);
	else if (quotes.x == 0 && info->quote == 0)
		error_in_name_and_comment(7, file->count_lines);
	else
		error_in_name_and_comment(key, file->count_lines);
}

void	cut_filename(t_all *info, char *av)
{
	int		i;

	i = 0;
	while (av[i] != '.')
		i++;
	info->filename = ft_strsub(av, 0, ft_strrchr(av, '.') - av);
}
