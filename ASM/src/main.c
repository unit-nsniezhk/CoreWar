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
    else if (error == 3)
		ft_putstr("Invalid parameter 0 type register for instruction \n");
	else if (error == 4)
		ft_putstr("Invalid parameter count for instruction\n");
	else if (error == 7)
		ft_putstr("Syntax error at token [TOKEN][001:010] INSTRUCTION \"zork\"\n");
	exit (0);
}

void 	print_err(int error, int row, int column)
{
	if (error == 1)
		ft_printf("Syntax error at token [TOKEN][00%d:00%d] COMMAND_NAME \".name\"\n", row, column);
	else if (error == 2)
		ft_printf("Syntax error at token [TOKEN][00%d:00%d] COMMAND_COMMENT \".comment\"\n", row, column);
	else if (error == 3)
		ft_printf("Syntax error at token [TOKEN][00%d:00%d] END \"(null)\"", row, column);
	else if (error == 4)
		ft_printf("Syntax error at token [TOKEN][00%d:00%d] ENDLINE", row, column);
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
			if (ft_strlen(argv[i]) < 3 || argv[i][ft_strlen(argv[i]) - 2] != '.' ||
				argv[i][ft_strlen(argv[i]) - 1] != 's')
			print_error(2);
		}
		read_file_asm(argv);
	}
	return (0);
}
