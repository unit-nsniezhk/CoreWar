/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_champion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:15:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 21:45:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft.h"
#include "parse.h"

static int	static_parse2(t_parse *parse, t_parse_champ *parse_champ,
			const char *line)
{
	if (line[parse_champ->i] && !parse_champ->comment)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_COMMENT))
			return (0);
	}
	if (line[parse_champ->i] && !parse_champ->second_null)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_NULL))
			return (0);
	}
	if (line[parse_champ->i] && !parse_champ->code)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_CODE))
			return (0);
	}
	if (!line[parse_champ->i] && parse_champ->i == 0)
	{
		ft_printf(ERROR_LINE, ERROR_LINE2,
		parse_champ->champion, parse_champ->line);
		return (0);
	}
	return (1);
}

static int	static_parse(t_parse *parse, t_parse_champ *parse_champ,
			const char *line)
{
	if (!parse_champ->magic_header)
	{
		if (!corewar_parse_line(
		parse, parse_champ, line, MODE_MAGIC_HEADER))
			return (0);
	}
	if (line[parse_champ->i] && !parse_champ->name)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_NAME))
			return (0);
	}
	if (line[parse_champ->i] && !parse_champ->first_null)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_NULL))
			return (0);
	}
	if (line[parse_champ->i] && !parse_champ->code_size)
	{
		if (!corewar_parse_line(parse, parse_champ, line, MODE_CODE_SIZE))
			return (0);
	}
	if (line[parse_champ->i])
		return (static_parse2(parse, parse_champ, line));
	return (1);
}

static void	static_init(t_parse_champ *parse_champ, const char *champion)
{
	parse_champ->champion = champion;
	parse_champ->line = 0;
	parse_champ->tmp_i = 0;
	parse_champ->magic_header = 0;
	parse_champ->name = 0;
	parse_champ->first_null = 0;
	parse_champ->code_size = 0;
	parse_champ->comment = 0;
	parse_champ->second_null = 0;
	parse_champ->code = 0;
}

int			corewar_parse_champion(t_parse *parse, const char *champion)
{
	t_parse_champ	parse_champ;
	int				fd;
	char			*line;

	if ((fd = open(champion, O_RDONLY)) == -1)
	{
		ft_printf(ERROR_CHAMPION, ERROR_CHAMPION3, champion);
		return (0);
	}
	static_init(&parse_champ, champion);
	while (ft_gnl(fd, &line) == 1)
	{
		parse_champ.i = 0;
		parse_champ.bytes = 0;
		if (!static_parse(parse, &parse_champ, line))
			return (0);
		parse_champ.line++;
 	}
	if (!parse_champ.code)
	{
		ft_printf(ERROR_CHAMPION, ERROR_CHAMPION4, champion);
		return (0);
	}
	return (1);
}
