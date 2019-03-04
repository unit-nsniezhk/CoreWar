/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:59:00 by sbudilko          #+#    #+#             */
/*   Updated: 2019/03/04 14:59:01 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_error(int error)
{
	if (error == 1)
		ft_putstr("Usage: ./asm <sourcefile.s>\n"); 
	else if (error == 2)
		ft_putstr("Can not read source file \n");
	exit (0);
}


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
			ft_putstr(argv[i]);
			ft_putstr(": ");
			if (ft_strlen(argv[i]) < 3 || argv[i][ft_strlen(argv[i]) - 2] != '.' ||
				argv[i][ft_strlen(argv[i]) - 1] != 's')
			print_error(2);
		}
	}
	
	return (0);
}
