/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:15:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/28 22:19:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft.h"
#include "corewar.h"

static int static_get_pos(t_parse *parse)
{
	unsigned int i;

	if (parse->pos == 0)
	{
		i = 0;
		while (parse->champs[i].id != 0 && i < MAX_PLAYERS)
			++i;
		if (i == MAX_PLAYERS)
		{
			ft_printf("Eerrr");
			return (0);
		}
		parse->pos = i + 1;
	}
	else
	{
		if (parse->champs[parse->pos - 1].id)
		{
			ft_printf("rr");
			return (0);
		}
	}
	return (1);
}

static int	static_parse2(t_parse *parse, const char *line)
{
	if (line[parse->i] && !parse->comment)
	{
		if (!corewar_parse_line(parse, line, MODE_COMMENT))
			return (0);
	}
	if (line[parse->i] && !parse->second_null)
	{
		if (!corewar_parse_line(parse, line, MODE_NULL))
			return (0);
	}
	if (line[parse->i])
	{
		if (!corewar_parse_line(parse, line, MODE_CODE))
			return (0);
	}
	if (!line[parse->i] && parse->i == 0)
	{
		ft_printf("error end");
		return (0);
	}
	return (1);
}

static int	static_parse(t_parse *parse, const char *line)
{
	if (!parse->magic_header)
	{
		if (!corewar_parse_line(parse, line, MODE_MAGIC_HEADER))
			return (0);
	}
	if (line[parse->i] && !parse->name)
	{
		if (!corewar_parse_line(parse, line, MODE_NAME))
			return (0);
	}
	if (line[parse->i] && !parse->first_null)
	{
		if (!corewar_parse_line(parse, line, MODE_NULL))
			return (0);
	}
	if (line[parse->i] && !parse->code_size)
	{
		if (!corewar_parse_line(parse, line, MODE_CODE_SIZE))
			return (0);
	}
	if (line[parse->i])
		return (static_parse2(parse, line));
	return (1);
}

static void	static_init(t_parse *parse)
{
	parse->line = 0;
	parse->tmp_i = 0;
	parse->magic_header = 0;
	parse->name = 0;
	parse->comment = 0;
	parse->code_size = 0;
	parse->first_null = 0;
	parse->second_null = 0;
}

int			corewar_parse_champion_loop(char *str, t_parse *parse)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_printf("error");
		return (0);
	}
	if (!static_get_pos(parse))
		return (0);
	static_init(parse);
	while (ft_gnl(fd, &line) == 1)
	{
		parse->bytes = 0;
		parse->i = 0;
		if (!static_parse(parse, line))
			return (0);
 	}
	if (parse->bytes != parse->champs[parse->pos - 1].code_size)
	{
		ft_printf("error");
		return (0);
	}
	parse->pos = 0;
	return (1);
}
