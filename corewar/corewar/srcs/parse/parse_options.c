/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:02:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 21:45:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static int	static_value(const char *string_value, unsigned int *value,
			const char *option)
{
	unsigned int	i;

	i = 0;
	while (string_value[i])
	{
		if (string_value[i] < '0' || string_value[i] > '9')
		{
			ft_printf(ERROR_OPTIONS6, ERROR_OPTIONS7, option);
			return (0);
		}
		++i;
	}
	*value = (int)ft_atouibase(HEX, string_value);
	return (1);
}

static int	static_option_n(t_parse *parse, const char *string_value)
{
	unsigned int	value;

	if (!static_value(string_value, &value, "-n"))
		return (0);
	if (value == 0 || value > MAX_PLAYERS)
	{
		ft_printf(ERROR_OPTIONS, ERROR_OPTIONS5, value);
		return (0);
	}
	parse->pos = value;
	return (1);
}

static int	static_option_dump(t_parse *parse, const char *string_value)
{
	unsigned int value;

	if (parse->dump != 0)
	{
		ft_printf(ERROR_OPTIONS, ERROR_OPTIONS3, parse->dump);
		return (0);
	}
	if (!static_value(string_value, &value, "-dump"))
		return (0);
	if (value == 0)
	{
		ft_printf(ERROR_OPTIONS, ERROR_OPTIONS4, value);
		return (0);
	}
	parse->dump = value;
	return (1);
}

int			corewar_parse_options(t_parse *parse, const char **argv,
			unsigned int i)
{
	if (argv[i][1] == 'n' && !argv[i][2])
	{
		if (parse->pos)
		{
			ft_printf(ERROR_OPTIONS, ERROR_OPTIONS2, parse->pos);
			return (0);
		}
		if (!static_option_n(parse, argv[i + 1]))
			return (0);
	}
	else if (ft_strncmp(&(argv[i][1]), "dump", 5))
	{
		if (!static_option_dump(parse, argv[i + 1]))
			return (0);
	}
	else
	{
		ft_printf(ERROR_OPTIONS9, ERROR_OPTIONS10, argv[i]);
		return (0);
	}
	return (1);
}
