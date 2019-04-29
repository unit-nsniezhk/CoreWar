/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:34:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 22:37:45 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static int	static_valid(t_parse *parse)
{
	unsigned int	i;

	if (parse->n_champs < MIN_PLAYERS)
	{
		ft_printf(ERROR_CHAMPION8, ERROR_CHAMPION9, MAX_PLAYERS,
		ERROR_CHAMPION11);
		return (0);
	}
	i = 0;
	while (i < parse->n_champs)
	{
		if (!parse->champs[i].id)
		{
			ft_printf(ERROR_OPTIONS8, i + 1);
			return (0);
		}
		if (parse->champs[i].code_size > CHAMP_MAX_SIZE)
		{
			ft_printf(ERROR_CHAMPION6, ERROR_CHAMPION7, CODE_SIZE_LENGTH,
			parse->champs[i].name);
			return (0);
		}
		++i;
	}
	return (1);
}

static int static_pos(t_parse *parse)
{
	unsigned int i;

	if (!parse->pos)
	{
		i = 0;
		while (parse->champs[i].id != 0 && i < MAX_PLAYERS)
			++i;
		if (i == MAX_PLAYERS)
		{
			ft_printf(ERROR_CHAMPION8, ERROR_CHAMPION10, MAX_PLAYERS,
			ERROR_CHAMPION11);
			return (0);
		}
		parse->pos = i + 1;
	}
	else
	{
		if (parse->champs[parse->pos - 1].id)
		{
			ft_printf(ERROR_CHAMPION, ERROR_CHAMPION2);
			return (0);
		}
	}
	parse->champs[parse->pos - 1].id = parse->pos;
	return (1);
}

static void	static_init(t_parse *parse)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		parse->champs[i].id = 0;
		parse->champs[i].code_size = 0;
		parse->champs[i].code = NULL;
		++i;
	}
	parse->pos = 0;
	parse->dump = 0;
	parse->n_champs = 0;
}

int			corewar_parse(t_parse *parse, unsigned int argc, const char **argv)
{
	unsigned int	i;

	static_init(parse);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (!corewar_parse_options(parse, argv, i))
				return (0);
			++i;
		}
		else
		{
			if (!static_pos(parse) || !corewar_parse_champion(parse, argv[i]))
				return (0);
			parse->pos = 0;
			parse->n_champs++;
		}
		++i;
	}
	if (!static_valid(parse))
		return (0);
	return (1);
}
