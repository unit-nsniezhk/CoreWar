/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_codetype.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:37:58 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/14 13:37:58 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

int		cmp_token(int token)
{
	int a;

	a = 0;
	if (token == REGISTER)
		a = REG_CODE;
	else if (token == DIRECT || token == DIRECT_LABEL)
		a = DIR_CODE;
	else if (token == INDEX)
		a = IND_CODE;
	return (a);
}

void	determine_codetype(char *result, int i, t_all *info)
{
	char	codetype;
	int		a;
	int		repeats;

	a = 0;
	codetype = 0;
	repeats = 0;
	i++;
	while (i < info->number_tokens && info->tokens[i].token != INSTRUCTION &&\
	info->tokens[i].token != LABEL)
	{
		a = cmp_token(info->tokens[i].token);
		codetype = codetype << 2 | a;
		i++;
		repeats++;
	}
	while (repeats < 4)
	{
		codetype = codetype << 2;
		repeats++;
	}
	write_bytes(result, codetype, &info->byte, 1);
}
