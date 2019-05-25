/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:25 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/13 13:14:26 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void		check_instruct_arg(t_all *info)
{
	int i;

	i = -1;
	while (++i < info->number_tokens)
	{
		if (info->tokens[i].token == INSTRUCTION)
		{
			check_numb_instruct_arg(info, i);
		}
	}
}

void		get_first_line(t_all *info)
{
	t_file	*dop;
	int		quotes;

	dop = info->begin;
	quotes = 0;
	while (dop->next && quotes != 4)
	{
		quotes += count_symbols(dop->line, '"');
		dop = dop->next;
	}
	info->after_comment = dop->next;
}

void		clean_file(t_file *file)
{
	t_file	*tmp;

	while (file && file->next)
	{
		tmp = file->next;
		free(file->line);
		file = tmp;
	}
}

void		is_instruction(t_all *info, t_file *file, int *i, char **rest)
{
	info->tokens[info->n].name = NULL;
	info->tokens[info->n].value = g_op[--(*i)].opcode;
	info->tokens[info->n++].token = INSTRUCTION;
	cut_last((*rest), info, file->count_lines);
}

void		write_info(t_all *info)
{
	int		i;
	char	*admit;
	char	*rest;
	int		cmp;
	t_file	*file;

	get_first_line(info);
	file = info->after_comment;
	while (file && file->next)
	{
		i = -1;
		cmp = 1;
		cut_label(file->line, &admit, info);
		cut_instruction(&admit, &rest, file->count_lines);
		while (++i < NUMB_INSTRUCTION && cmp != 0)
			cmp = ft_strcmp(admit, g_op[i].instruction);
		if (cmp == 0)
			is_instruction(info, file, &i, &rest);
		file = file->next;
		free(admit);
		free(rest);
	}
	is_labels(info);
	check_instruct_arg(info);
	clean_file(file);
}
