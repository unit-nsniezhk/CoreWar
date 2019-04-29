/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 20:12:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "corewar_defines.h"
# include "corewar_parse_defines.h"

int	corewar_parse(t_parse *parse, unsigned int argc, const char **argv);

#endif
