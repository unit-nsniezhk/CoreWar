/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:19:12 by ychufist          #+#    #+#             */
/*   Updated: 2019/05/10 18:19:14 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_error(int error)
{
	write(1, "\e[31m", 5);
	if (error == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else if (error == 2)
		ft_printf("CAN NOT READ SOURCE FILE!\n");
	else if (error == 3)
		ft_printf("FILE .cor IS NOT CREATED!\n");
	else if (error == 4)
		ft_printf("CLOSE FAILED!\n");
	else if (error == 5)
		ft_printf("ERROR. COULD NOT OPEN THE FILE!\n");
	write(1, "\e[0m", 4);
	exit(0);
}

void	print_err(int error, int row, char *line)
{
	write(1, "\e[31m", 5);
	if (error == 2)
		ft_printf("ERROR. %s!\n", row, ERROR3);
	else if (error == 3)
		ft_printf("ERROR. NO LINK REFERED!\n");
	else if (error == 4)
		ft_printf("ERROR. %s \"%s\"!\n", ERROR4, line);
	else if (error == 5)
		ft_printf("ERROR. %s \"%s\"!\n", ERROR5, row, line);
	else if (error == 6)
		ft_printf("ERROR. CHECK SYNTAX IN LINE %d!\n", row);
	else if (error == 7)
		ft_printf("ERROR. CHECK COMMAS AROUND ARGUMENTS IN LINE %d!\n", row);
	else if (error == 8)
		ft_printf("ERROR. CHECK NAME OF INSTRUCTION IN LINE %d!\n", row);
	else if (error == 9)
		ft_printf("ERROR. CHECK SYNTAX OF ARGUMENTS!\n");
	else if (error == 10)
		ft_printf("ERROR. NO NAME AND COMMENT. CHECK LINE %d!\n", row);
	write(1, "\e[0m", 4);
	exit(0);
}

void	double_symbols_error(int error, char c, int row)
{
	write(1, "\e[31m", 5);
	if (error == 1)
		ft_printf("ERROR. CHECK symbols \'%c\' in line %d!\n", c, row);
	write(1, "\e[0m", 4);
	exit(0);
}

void	error_in_name_and_comment(int error, int row)
{
	write(1, "\e[31m", 5);
	if (error == 1)
		ft_printf("ERROR. CHECK \".name\" IN LINE %d!\n", row);
	else if (error == 2)
		ft_printf("ERROR. CHECK \".comment\" IN LINE %d!\n", row);
	else if (error == 3)
		ft_printf("Syntax error at token [TOKEN][00%d] END \"(null)\"!", row);
	else if (error == 4)
		ft_printf("Syntax error at token [TOKEN][00%d] ENDLINE!", row);
	else if (error == 5 && row == 1)
		ft_printf("ERROR. CHAMPION NAME IS TOO LONG. (Max length 128)!\n");
	else if (error == 5 && row == 2)
		ft_printf("ERROR. COMMENT IS TOO LONG. (Max length 2048)\n");
	else if (error == 6 && row == 1)
		ft_printf("ERROR. %s\".name \"text\"\"!\n", ERROR61);
	else if (error == 6 && row == 2)
		ft_printf("ERROR. %s\".comment \"text\"\"!\n", ERROR62);
	else if (error == 7)
		ft_printf("ERROR. NO QUOTES. CHECK LINE %d!\n", row);
	write(1, "\e[0m", 4);
	exit(0);
}
