/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_code_to_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:02:40 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/06 14:02:41 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

int		return_to_instr(int i, t_all *info)
{
	int j;

	j = i;
	while (info->tokens[j].token != INSTRUCTION)
		j--;
	return (j);
}

void	count_index(t_all *info, int i, int opcode)
{
	if (info->tokens[i].token == INDEX)
		info->n = 2;
	else
		info->n = g_op[opcode - 1].label;
}

void	direct_label_to_byte(char *result, t_all *info, int i, int opcode)
{
	int j;
	int diff;
	int instr;

	j = -1;
	count_index(info, i, opcode);
	while (++j < info->number_tokens)
	{
		if (info->tokens[j].token == LABEL &&\
		!ft_strcmp(info->tokens[j].name, info->tokens[i].name))
		{
			while (info->tokens[j].token != INSTRUCTION &&\
			j < info->number_tokens)
				j++;
			if (info->tokens[j].size == 0)
				info->tokens[j].size = SIZE_TO_EXECCODE +\
				count_code_size(info, j);
			instr = return_to_instr(i, info);
			diff = info->tokens[j].size - info->tokens[instr].size;
			if (diff < 0)
				write_bytes(result, INVERT, &info->byte, info->n);
			else
				write_bytes(result, diff, &info->byte, info->n);
		}
	}
}

void	if_reg_and_dir(char *result, t_all *info, int i, int opcode)
{
	if (info->tokens[i].token == REGISTER)
		write_bytes(result, info->tokens[i].value, &info->byte, 1);
	else if (info->tokens[i].token == DIRECT)
		write_bytes(result, info->tokens[i].value,\
		&info->byte, g_op[opcode - 1].label);
	else if (info->tokens[i].token == DIRECT_LABEL)
		direct_label_to_byte(result, info, i, opcode);
	else if (info->tokens[i].token == INDEX)
	{
		if (info->tokens[i].value && info->tokens[i].name == NULL)
			write_bytes(result, info->tokens[i].value, &info->byte, 2);
		else
			direct_label_to_byte(result, info, i, opcode);
	}
}

void	exec_code_to_byte(char *result, t_all *info)
{
	int i;
	int opcode;

	i = 0;
	opcode = 0;
	while (i < info->number_tokens)
	{
		info->tokens[i].size = info->byte;
		if (info->tokens[i].token == INSTRUCTION)
		{
			opcode = (int)info->tokens[i].value;
			if (g_op[opcode - 1].codage == 1)
			{
				write_bytes(result, opcode, &info->byte, 1);
				determine_codetype(result, i, info);
			}
			else
				write_bytes(result, opcode, &info->byte, 1);
		}
		else if (info->tokens[i].token == REGISTER ||\
		info->tokens[i].token == DIRECT_LABEL ||\
		info->tokens[i].token == DIRECT || info->tokens[i].token == INDEX)
			if_reg_and_dir(result, info, i, opcode);
		i++;
	}
}
