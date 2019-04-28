/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/28 22:22:07 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# define COREWAR_NULL 0

# define MAX_BYTES_PER_LINE 16
# define MODE_MAGIC_HEADER 1
# define MODE_NAME 2
# define MODE_NULL 3
# define MODE_CODE_SIZE 4
# define MODE_COMMENT 5
# define MODE_CODE 6

# define MAGIC_HEADER_LENGTH 4
# define NULL_LENGTH 4
# define CODE_SIZE_LENGTH 4

#include "defines.h"

typedef struct		s_champ
{
	unsigned int	id;
	unsigned char	name[PROG_NAME_LENGTH];
	unsigned char	comment[COMMENT_LENGTH];
	unsigned int	code_size;
	unsigned char	*code;
}					t_champ;

typedef struct		s_parse
{
	unsigned int	pos;
	unsigned int	line;//TODO add counter & display within errors
	unsigned int	i;
	unsigned int	tmp_i;
	unsigned int	bytes;
	unsigned int	magic_header : 1;
	unsigned int	name : 1;
	unsigned int	comment : 1;
	unsigned int	code_size : 1;
	unsigned int	first_null : 1;
	unsigned int	second_null : 1;
	t_champ			champs[MAX_PLAYERS];
}					t_parse;

typedef struct		s_corewar
{
	unsigned int	dump;
	unsinged int	champs;
}					t_corewar;

int		corewar_parse(int argc, char **argv, t_parse *parse,
		t_corewar *corewar);
int		corewar_parse_line(t_parse *parse, const char *line, char mode);
int		corewar_parse_champion_loop(char *str, t_parse *parse);


#endif
