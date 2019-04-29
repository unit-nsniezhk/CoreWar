/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_defines.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:29:37 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 22:37:55 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_PARSE_DEFINES_H

# define COREWAR_PARSE_DEFINES_H

# include "corewar_settings.h"

# define MODE_MAGIC_HEADER 1
# define MODE_NAME 2
# define MODE_NULL 3
# define MODE_CODE_SIZE 4
# define MODE_COMMENT 5
# define MODE_CODE 6

typedef struct		s_champ
{
	unsigned int	id;
	char			name[CHAMPION_NAME_LENGTH + 1];
	char			comment[CHAMPION_COMMENT_LENGTH + 1];
	unsigned int	code_size;
	unsigned char	*code;
}					t_champ;

typedef struct		s_parse_champ
{
	const char		*champion;
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
	unsigned int	code : 1;
}					t_parse_champ;

typedef struct		s_parse
{
	unsigned int	dump;
	unsigned int	n_champs;
	unsigned int	pos;
	t_champ			champs[MAX_PLAYERS];
}					t_parse;

#endif
