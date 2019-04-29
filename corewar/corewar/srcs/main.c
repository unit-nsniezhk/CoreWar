/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 23:10:26 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "parse.h"

static void	static_init_carriage(t_game_data *data, t_player *player)
{
	;
}

void	corewar_init_arena(t_game_data *data, t_parse *parse)
{
	unsigned int	i;
	unsigned int	code_i;

	i = 0;
	while (i < parse->n_champs)
	{
		data->players[i].id = parse->champs[i].id;
		data->players[i].pos = MEM_SIZE / parse->n_champs * i;
		code_i = 0;
		while (code_i < parse->champs[i].code_size)
		{
			data->arena[data->players[i].pos + code_i] =
			parse->champs[i].code[code_i];
			++code_i;
		}
		static_init_carriage(data, &(data->players[i]));
		++i;
	}
}

static void	static_init_data(t_game_data *data, t_parse *parse)
{
	data->cycle = 0;
	data->live_executed = 0;
	data->n_players = parse->n_champs;
	data->leading_player = parse->n_champs;
	data->death_checks = 0;
	data->carriages = NULL;
}

int	main(int argc, char **argv)
{
	t_parse		parse;
	t_game_data	data;

	if (!corewar_parse(&parse, (unsigned int)argc, (const char **)argv))
	{
		ft_printf("Usage");
		return (0);
	}
	static_init_data(&data, &parse);
	corewar_init_arena(&data, &parse);
	//TODO adduce players
	//TODO add switch to sdl2 visualisation
	//TODO start game
	return (0);
}
