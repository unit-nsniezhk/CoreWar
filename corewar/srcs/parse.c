/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:34:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/28 22:48:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	static_value(const char *str, unsigned *nbr)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_printf("Error ..");
			return (0);
		}
		++i;
	}
	*nbr = (int)ft_atouibase(HEX, str);
	return (1);
}

static int	static_option_n(t_parse *parse, char *str)
{
	unsigned int	nbr;

	if (!static_value(str, &nbr))
		return (0);
	if (nbr == 0 || nbr > MAX_PLAYERS)
	{
		ft_printf("error");
		return (0);
	}
	parse->pos = nbr;
	return (1);
}

static int	static_option_dump(char *str, t_corewar *corewar)
{
	unsigned int nbr;

	if (corewar->dump != 0)
	{
		ft_printf("errop");
		return (0);
	}
	if (!static_value(str, &nbr))
		return (0);
	if (nbr == 0)
	{
		ft_printf("errr");
		return (0);
	}
	corewar->dump = nbr;
	return (1);
}

static int	parse_options(unsigned int i, char **argv, t_parse *parse,
			t_corewar *corewar)
{
	if (argv[i][1] == 'n' && !argv[i][2])
	{
		if (parse->pos)
		{
			ft_printf("erro");
			return (0);
		}
		if (!static_option_n(parse, argv[i + 1]))
			return (0);
		parse->pos = 1;
	}
	else if (ft_strncmp(&(argv[i][1]), "dump", 5))
	{
		if (!static_option_dump(argv[i + 1], corewar))
			return (0);
	}
	else
	{
		ft_printf("Error invalid option");
		return (0);
	}
	return (1);
}

int			corewar_parse(int argc, char **argv, t_parse *parse,
			t_corewar *corewar)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (argv[i][0] == '-')
		{
			if (!parse_options((unsigned int)i, argv, parse, corewar))
				return (0);
			++i;
		}
		else
		{
			if (!corewar_parse_champion_loop(argv[i], parse))
				return (0);
			corewar->champs++;
		}
		++i;
	}
	if (corewar->champs < 2)
	{
		ft_printf("error");
		return (0);
	}
	return (1);
}
