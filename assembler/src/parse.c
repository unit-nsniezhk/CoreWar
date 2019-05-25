/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:53:38 by amartyne          #+#    #+#             */
/*   Updated: 2019/04/23 13:53:39 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

int		count_code_size(t_all *info, int len)
{
	int		size;
	int		i;

	size = 0;
	i = -1;
	info->opcode = 0;
	while (++i < len)
	{
		if (info->tokens[i].token == INSTRUCTION)
		{
			info->opcode = (int)info->tokens[i].value;
			if (g_op[info->opcode - 1].codage == 1)
				size += 2;
			else
				size += 1;
		}
		else if (info->tokens[i].token == REGISTER)
			size += 1;
		else if (info->tokens[i].token == DIRECT ||\
		info->tokens[i].token == DIRECT_LABEL)
			size += g_op[info->opcode - 1].label;
		else if (info->tokens[i].token == INDEX)
			size += 2;
	}
	return (size);
}

void	write_bytes(char *result, int n, int *start, int len)
{
	int count;
	int length;

	length = len;
	count = 0;
	while (len)
	{
		result[(*start) + len - 1] = (n >> count) & 0xFF;
		count += 8;
		len--;
	}
	(*start) += length;
}

int		write_championname_comment(char *result, t_all *info, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write_bytes(result, str[i], &info->byte, 1);
		i++;
	}
	return (i);
}

void	parse(t_all *info)
{
	int		fd;
	char	*result;
	int		position;

	info->new_filename = ft_strjoin(info->filename, ".cor");
	if ((fd = open(info->new_filename, O_CREAT | O_TRUNC | O_WRONLY,\
	S_IRUSR | S_IWUSR)) == -1)
		print_error(3);
	info->exec_code_size = count_code_size(info, info->number_tokens);
	info->all_code_size = SIZE_TO_EXECCODE + info->exec_code_size;
	result = ft_strnew((size_t)info->all_code_size);
	if (!result)
		ft_printf("ERROR\n");
	ft_bzero(result, (size_t)info->all_code_size);
	write_bytes(result, COREWAR_EXEC_MAGIC, &info->byte, 4);
	position = write_championname_comment(result, info, info->champion_name);
	info->byte += PROG_NAME_LENGTH - position + 4;
	write_bytes(result, info->exec_code_size, &info->byte, 4);
	position = write_championname_comment(result, info, info->comment);
	info->byte += COMMENT_LENGTH - position + 4;
	exec_code_to_byte(result, info);
	write(fd, result, (size_t)info->all_code_size);
	(close(fd) == -1) ? print_error(4) : ft_printf(OUTPUT, info->new_filename);
	free(result);
}
