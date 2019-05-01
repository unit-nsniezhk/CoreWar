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

char	*cut_filename(char *av)
{
	int		i;
	char	*admit;

	i = 0;
	while (av[i] != '.')
		i++;
	admit = ft_strsub(av, 0, i);
	return(admit);
}

char	*cut_instruction(char *line, char **rest)
{
	int i;
	char *admit;
	char *tmp;

	tmp = ft_strtrim(line);
	i = 0;
	while (ft_isalpha(tmp[i]))
		i++;
	admit = ft_strsub(tmp, 0, i);
	(*rest) = ft_strsub(tmp, (i + 1), ft_strlen(tmp));
	free(tmp);
	return(admit);
}

void	cut_last(char *rest, t_all *info)
{
	char **last;
	int i;
	char *tmp;

	last = ft_strsplit(rest, ',');
	i = -1;
	while (last[++i])
	{
		tmp = ft_strtrim(last[i]);
		printf("         |%s|   \n", tmp);
		if (tmp[0] == 'r')
		{
			info->tokens[info->n].name = ft_strdup(tmp);
			printf("%d, %s ", info->n, info->tokens[info->n].name);
			info->tokens[info->n++].token = REGISTER;
			printf("%d\n", info->n);
		}else if (tmp[0] == DIRECT_CHAR)
		{
			info->tokens[info->n].name = ft_strdup(tmp);
			printf("%d, %s ", info->n, info->tokens[info->n].name);
			info->tokens[info->n++].token = DIRECT;
			printf("%d\n", info->n);
		}
	}
}