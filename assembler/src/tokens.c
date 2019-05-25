/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:18:33 by ychufist          #+#    #+#             */
/*   Updated: 2019/05/10 19:09:42 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	write_direct_tokens(char *tmp, t_all *info, int i)
{
	if (count_symbols(tmp, DIRECT_CHAR) != 1)
		double_symbols_error(1, '%', i);
	if (tmp[1] == '-')
	{
		if (count_symbols(tmp, '-') != 1)
			double_symbols_error(1, '-', i);
		info->tokens[info->n].name = NULL;
		info->tokens[info->n].value = ((0xFFFFFFFF ^ check_digit(&tmp[2])) + 1);
		info->tokens[info->n++].token = DIRECT;
	}
	else if (ft_isdigit(tmp[1]))
	{
		info->tokens[info->n].name = NULL;
		info->tokens[info->n].value = check_digit(&tmp[1]);
		info->tokens[info->n++].token = DIRECT;
	}
	else if (tmp[1] == LABEL_CHAR)
	{
		if (count_symbols(tmp, LABEL_CHAR) != 1)
			double_symbols_error(1, LABEL_CHAR, i);
		info->tokens[info->n].name = ft_strdup(&tmp[2]);
		info->tokens[info->n].value = 0;
		info->tokens[info->n++].token = DIRECT_LABEL;
	}
}

void	write_indirect_tokens(char *tmp, t_all *info, int i)
{
	if (count_symbols(tmp, LABEL_CHAR) > 2 || count_symbols(tmp, '-') > 2)
		double_symbols_error(1, LABEL_CHAR, i);
	if (tmp[0] == LABEL_CHAR)
	{
		info->tokens[info->n].value = 0;
		info->tokens[info->n].name = ft_strdup(&tmp[1]);
		info->tokens[info->n++].token = INDEX;
	}
	else if (tmp[0] == '-')
	{
		info->tokens[info->n].name = NULL;
		info->tokens[info->n].value = ((0xFFFFFFFF ^ check_digit(&tmp[1])) + 1);
		info->tokens[info->n++].token = INDEX;
	}
	else if (ft_isdigit(tmp[0]))
	{
		info->tokens[info->n].name = NULL;
		info->tokens[info->n].value = check_digit(tmp);
		info->tokens[info->n++].token = INDEX;
	}
}

int		valid_direct(char *line, int n)
{
	int i;

	i = -1;
	if (!ft_isalnum(line[i]) && (ft_strlen(line) == 0 ||
	(ft_strlen(line) == 1 && (line[0] == ':' || line[0] == '-'))))
		print_err(6, n, NULL);
	while (line[++i])
	{
		if (line[0] == '-' || line[0] == ':')
			continue;
		else if (!ft_isalnum(line[i]))
			return (0);
	}
	return (1);
}
