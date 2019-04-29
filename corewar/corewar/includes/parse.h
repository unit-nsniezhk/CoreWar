/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:36:52 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 20:12:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_PARSE_H

# define COREWAR_PARSE_H

# include "corewar_parse_defines.h"
# include "corewar_errors.h"

int	corewar_parse_options(t_parse *parse, const char **argv,
	unsigned int i);

int	corewar_parse_champion(t_parse *parse, const char *champion);
int	corewar_parse_line(t_parse *parse,
	t_parse_champ *parse_champ, const char *champion, char mode);

#endif
