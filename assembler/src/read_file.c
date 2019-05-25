/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:22:39 by amartyne          #+#    #+#             */
/*   Updated: 2019/04/16 15:22:42 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void		clean(t_all *info)
{
	t_file	*tmp;
	int		i;

	i = -1;
	free(info->champion_name);
	free(info->comment);
	free(info->filename);
	free(info->new_filename);
	while (info->begin)
	{
		tmp = info->begin->next;
		free(info->begin->line);
		free(info->begin);
		info->begin = tmp;
	}
	free(info->begin);
	while (++i < info->number_tokens)
		free(info->tokens[i].name);
	free(info->tokens);
}

void		check_hash(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(*line, '#') && ft_strchr(*line, ';'))
		i = ft_strchr(*line, '#') - ft_strchr(*line, ';');
	if (ft_strchr(*line, '#') || i < 0)
	{
		tmp = ft_strsub(*line, 0, ft_strchr(*line, '#') - (*line));
		ft_strdel(line);
		(*line) = ft_strdup(tmp);
		free(tmp);
	}
	else if (ft_strchr(*line, ';') || i > 0)
	{
		tmp = ft_strsub(*line, 0, ft_strchr(*line, ';') - (*line));
		ft_strdel(line);
		(*line) = ft_strdup(tmp);
		free(tmp);
	}
}

void		after_read_file(t_all *info, int i)
{
	if (!info->is_name)
		error_in_name_and_comment(6, 1);
	if (!info->is_comment)
		error_in_name_and_comment(6, 2);
	info->lines_in_file = --i;
	if (info->number_tokens == 0)
		print_err(2, info->lines_in_file, NULL);
	else
	{
		info->tokens = (t_code*)malloc(sizeof(t_code) * info->number_tokens);
		write_info(info);
		parse(info);
	}
}

int			initialization(t_all *info, t_file **file)
{
	int i;

	i = 1;
	info->number_tokens = 0;
	info->is_comment = 0;
	info->is_name = 0;
	info->tokens = NULL;
	info->new_filename = NULL;
	info->n = 0;
	info->opcode = 0;
	info->quote = 0;
	info->tmp = NULL;
	info->all_code_size = 0;
	info->exec_code_size = 0;
	info->byte = 0;
	info->args = 0;
	info->lines_in_file = 0;
	(*file) = (t_file*)malloc(sizeof(t_file));
	(*file)->line = NULL;
	(*file)->count_lines = i++;
	(*file)->next = NULL;
	return (i);
}

void		read_file_asm(char **av)
{
	int		fd;
	t_file	*file;
	t_all	info;
	int		i;

	i = initialization(&info, &file);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		print_error(5);
	cut_filename(&info, av[1]);
	info.begin = file;
	while (get_next_line(fd, &file->line))
	{
		check_hash(&file->line);
		if (ft_strlen(file->line) || info.quote == 1)
			check_line(file, &info);
		file->next = (t_file*)malloc(sizeof(t_file));
		file = file->next;
		file->count_lines = i++;
		file->next = NULL;
	}
	after_read_file(&info, i);
	clean(&info);
}
