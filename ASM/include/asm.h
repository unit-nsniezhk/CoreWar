/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:51:41 by sbudilko          #+#    #+#             */
/*   Updated: 2019/03/04 14:51:44 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libftprintf/includes/ft_printf.h"
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define NUMB_INSTRUCTION 17
# define LABEL 1
# define INSTRUCTION 2
# define REGISTER 3
# define SEPARATOR 4
# define DIRECT_LABEL 5
# define DIRECT 6

typedef struct  s_code
{
    unsigned char   name;
    int   token;

}               t_code;

typedef struct  s_all
{
    t_code  *tokens;
    int     number_tokens;

}               t_all;

typedef struct  s_file
{
    char            *line;
    struct s_file   *next;

}               t_file;

void    read_file();

#endif
