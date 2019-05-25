/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:58:42 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/14 13:58:44 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void		is_labels(t_all *info)
{
	int i;
	int j;
	int label;

	i = -1;
	label = 0;
	while (++i < info->number_tokens)
	{
		if (info->tokens[i].token == DIRECT_LABEL)
		{
			j = -1;
			while (++j < info->number_tokens)
			{
				if (info->tokens[j].token == LABEL &&
					!ft_strcmp(info->tokens[i].name, info->tokens[j].name))
					label++;
			}
			if (label != 1)
				print_err(3, 0, NULL);
			else
				label = 0;
		}
	}
}

void		check_numb_instruct_arg(t_all *info, int i)
{
	info->opcode = info->tokens[i].value;
	info->args = 0;
	while ((info->tokens[++i].token != INSTRUCTION &&\
	info->tokens[i].token != LABEL) && i <= info->number_tokens)
	{
		if (info->tokens[i].token == REGISTER ||\
		info->tokens[i].token == DIRECT ||\
		info->tokens[i].token == DIRECT_LABEL || info->tokens[i].token == INDEX)
		{
			if (info->tokens[i].token == REGISTER &&
				(g_op[info->opcode - 1].arguments[info->args] & T_REG) == 0)
				print_err(5, info->args, g_op[info->opcode - 1].instruction);
			else if ((info->tokens[i].token == DIRECT_LABEL ||\
			info->tokens[i].token == DIRECT) &&\
			(g_op[info->opcode - 1].arguments[info->args] & T_DIR) == 0)
				print_err(5, info->args, g_op[info->opcode - 1].instruction);
			else if (info->tokens[i].token == INDEX &&\
			(g_op[info->opcode - 1].arguments[info->args] & T_IND) == 0)
				print_err(5, info->args, g_op[info->opcode - 1].instruction);
			info->args++;
		}
	}
	if (g_op[info->opcode - 1].number_arg != info->args)
		print_err(4, 0, g_op[info->opcode - 1].instruction);
}
