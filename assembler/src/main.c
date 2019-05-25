/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:59:00 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/04 14:59:01 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		print_error(1);
	else
	{
		while (++i < argc)
		{
			if (ft_strlen(argv[i]) < 3 ||\
			argv[i][ft_strlen(argv[i]) - 2] != '.' ||\
			argv[i][ft_strlen(argv[i]) - 1] != 's')
				print_error(2);
		}
		read_file_asm(argv);
	}
	return (0);
}

int		count_symbols(char *str, char symbol)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == symbol)
			i++;
		str++;
	}
	return (i);
}
