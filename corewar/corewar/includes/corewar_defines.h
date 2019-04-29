/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_defines.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 23:00:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_DEFINES_H

# define COREWAR_DEFINES_H

# include "corewar_settings.h"

typedef struct			s_player
{
	unsigned int		id;
	unsigned int		pos;
}						t_player;

typedef struct			s_carriage
{
	unsigned int		id;
	unsigned int		carry;
	unsigned int		flag : 1;
	unsigned char		code;
	unsigned int		last_live_cycle;
	unsigned int		cycles_to_execute;
	unsigned int		pos;
	unsigned int		next_operation;
	unsigned int		registers[REG_NUMBER];//TODO innit to -player id of player - first, remaining to 0
	struct s_carriage	*next_carriage;
}						t_carriage;

typedef struct			s_game_data
{
	unsigned int		cycle;
	unsigned int		live_executed;
	unsigned char		arena[MEM_SIZE];
	unsigned int		leading_player;
	unsigned int		death_checks;
	unsigned int		n_players;
	t_carriage			*carriages;
	t_player			players[MAX_PLAYERS];
}						t_game_data;

#endif
