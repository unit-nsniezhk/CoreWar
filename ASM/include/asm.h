/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:51:41 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/04 14:51:44 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../src/libft/libft.h"
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "inttypes.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define NUMB_INSTRUCTION 16
# define LABEL 1
# define INSTRUCTION 2
# define REGISTER 3
# define SEPARATOR 4
# define DIRECT_LABEL 5
# define DIRECT 6
# define INDEX 7
# define SIZE_TO_EXECCODE (4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define INVERT ((0xFFFFFFFF ^ diff * (-1)) + 1)
# define ERROR2 "Syntax error at token [TOKEN][00%d INSTRUCTION"
# define ERROR3 "ENTER AT LEAST ONE COMMAND WITH PARAMETERS NEEDED"
# define ERROR4 "NOT ENOUGH OR TOO MANY ARGUMENTS IN INSTRUCTION"
# define ERROR5 "WRONG TYPE OF %d ARGUMENT IN INSTRUCTION"
# define ERROR61 "NO CHAMPION NAME. ADD "
# define ERROR62 "NO COMMENT. ADD "
# define OUTPUT "Writing output program to %s\n"

typedef struct			s_code
{
	char				*name;
	int					value;
	int					token;
	int					size;
}						t_code;

typedef struct			s_file
{
	char				*line;
	int					count_lines;
	struct s_file		*next;
}						t_file;

typedef struct			s_all
{
	char				*filename;
	char				*new_filename;
	char				*champion_name;
	char				*comment;
	char				*tmp;
	t_code				*tokens;
	int					n;
	int					opcode;
	int					args;
	int					is_name;
	int					is_comment;
	int					lines_in_file;
	int					number_tokens;
	int					quote;
	int					byte;
	int					exec_code_size;
	int					all_code_size;
	t_file				*after_comment;
	t_file				*begin;
}						t_all;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

void					read_file_asm(char **av);
void					print_error(int error);
void					print_err(int error, int row, char *line);
void					double_symbols_error(int error, char c, int row);
void					error_in_name_and_comment(int error, int row);
void					cut_filename(t_all *info, char *av);
int						cut_instruction(char **line, char **rest, int n);
void					cut_last(char *rest, t_all *info, int n);
void					cut_label(char *line, char **admit, t_all *info);
void					parse(t_all *info);
int						count_symbols(char *str, char symbol);
void					get_name_and_comment(t_file *file, t_all *info,\
int key);
void					check_line(t_file *file, t_all *info);
int						is_labelchars(char *line, int end);
void					exec_code_to_byte(char *result, t_all *info);
void					write_bytes(char *result, int n, int *start, int len);
int						count_code_size(t_all *info, int len);
void					check_instruct_arg(t_all *info);
void					write_direct_tokens(char *tmp, t_all *info, int i);
void					write_indirect_tokens(char *tmp, t_all *info, int i);
int						valid_direct(char *line, int n);
unsigned int			check_digit(char *line);
void					write_info(t_all *info);
void					determine_codetype(char *result, int i, t_all *info);
void					check_numb_instruct_arg(t_all *info, int i);
void					is_labels(t_all *info);
void					check_last_symb(char **av);

#endif
