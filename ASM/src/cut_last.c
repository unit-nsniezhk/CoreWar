/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:31:29 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/14 13:31:29 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void			free_last(char ***last)
{
	int i;

	i = -1;
	while ((*last)[++i])
		free((*last)[i]);
	free(*last);
}

void			choose_direct_indirect(char *tmp, t_all *info, int n)
{
	if (tmp[0] == DIRECT_CHAR)
	{
		if (valid_direct(&tmp[1], n))
			write_direct_tokens(tmp, info, n);
	}
	else if (tmp[0] == LABEL_CHAR || tmp[0] == '-' || ft_isdigit(tmp[0]))
	{
		if (valid_direct(&tmp[1], n))
			write_indirect_tokens(tmp, info, n);
	}
}

void			cut_last(char *rest, t_all *info, int n)
{
	char	**last;
	int		i;
	char	*tmp;

	last = ft_strsplit(rest, ',');
	i = -1;
	while (last[++i])
	{
		tmp = ft_strtrim(last[i]);
		if (tmp[0] == 'r')
		{
			info->tokens[info->n].name = NULL;
			info->tokens[info->n].value = check_digit(&tmp[1]);
			info->tokens[info->n++].token = REGISTER;
		}
		else if (tmp[0] == DIRECT_CHAR || tmp[0] == LABEL_CHAR ||\
		tmp[0] == '-' || ft_isdigit(tmp[0]))
			choose_direct_indirect(tmp, info, n);
		free(tmp);
	}
	free_last(&last);
}
