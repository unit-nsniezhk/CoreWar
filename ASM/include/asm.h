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

# include "../../libft/libft.h"
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
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

typedef struct          s_code
{
    char      			*name;
	int                 token;

}                       t_code;

typedef struct          s_all
{
    char                *filename;
    char                *champion_name;
    char				*comment;
    t_code              *tokens;
    int 				n;
    int 				is_name;
    int					is_comment;
    int                 number_tokens;

}                       t_all;

typedef struct          s_file
{
    char                *line;
    int 				n;
    struct s_file       *next;

}                       t_file;

void                    read_file_asm(char **av);
void                    print_error(int error);
void 					print_err(int error, int row, int column);
char					*cut_filename(char *av);
char					*cut_instruction(char *line, char **rest);
void					cut_last(char *rest, t_all *info);
void					validation(t_all *info);

#endif
