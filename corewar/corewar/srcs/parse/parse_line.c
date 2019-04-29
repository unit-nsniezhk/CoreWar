/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:01:16 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 21:45:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static int	parse_byte(t_parse_champ *parse_champ, const char *line,
			unsigned char *byte)
{
	while (line[parse_champ->i] == ' ')
		parse_champ->i++;
	if (!line[parse_champ->i])
		return (-1);
	if (!ft_strin(HEX, line[parse_champ->i]))
	{
		ft_printf(ERROR_LINE, ERROR_LINE5, parse_champ->champion,
		parse_champ->line);
		return (0);
	}
	if (parse_champ->bytes == BYTES_PER_LINE)
	{
		ft_printf(ERROR_LINE, ERROR_LINE6, parse_champ->champion,
		parse_champ->line);
		return (0);
	}
	*byte = (unsigned char)ft_antouibase(HEX, &line[parse_champ->i], 2);
	parse_champ->i++;
	if (ft_strin(HEX, line[parse_champ->i]))
		parse_champ->i++;
	parse_champ->bytes++;
	return (1);
}

static void	static_update(t_parse *parse, t_parse_champ *parse_champ, char mode)
{
	if (mode == MODE_NAME)
		parse_champ->name = 1;
	else if (mode == MODE_MAGIC_HEADER)
		parse_champ->magic_header = 1;
	else if (mode == MODE_NULL)
	{
		if (!parse_champ->first_null)
			parse_champ->first_null = 1;
		else
			parse_champ->second_null = 1;
	}
	else if (mode == MODE_CODE_SIZE)
	{
		parse->champs[parse->pos - 1].code =
		(unsigned char*)ft_strnew(parse->champs[parse->pos - 1].code_size + 1);
		parse_champ->code_size = 1;
	}
	else if (mode == MODE_COMMENT)
		parse_champ->comment = 1;
	else if (mode == MODE_CODE)
		parse_champ->code = 1;
}

static void	static_length(t_parse *parse, char mode, unsigned int *length)
{
	if (mode == MODE_NAME)
		*length = CHAMPION_NAME_LENGTH;
	else if (mode == MODE_MAGIC_HEADER)
		*length = MAGIC_HEADER_LENGTH;
	else if (mode == MODE_NULL)
		*length = MAGIC_NULL_LENGTH;
	else if (mode == MODE_CODE_SIZE)
		*length = CODE_SIZE_LENGTH;
	else if (mode == MODE_COMMENT)
		*length = CHAMPION_COMMENT_LENGTH;
	else if (mode == MODE_CODE)
		*length = parse->champs[parse->pos - 1].code_size;
}

static int	static_execute_mode(t_parse *parse, t_parse_champ *parse_champ,
			char mode, unsigned char byte)
{
	if (mode == MODE_NAME)
		parse->champs[parse->pos - 1].name[parse_champ->tmp_i] = byte;
	else if (mode == MODE_COMMENT)
		parse->champs[parse->pos - 1].comment[parse_champ->tmp_i] = byte;
	else if (mode == CODE_SIZE_LENGTH)
		parse->champs[parse->pos - 1].code_size =
		parse->champs[parse->pos - 1].code_size << 8 | (unsigned int)byte;
	else if (mode == MODE_MAGIC_HEADER && ((MAGIC_HEADER >>
	(8 * (MAGIC_HEADER_LENGTH - parse_champ->tmp_i - 1))) & 255) != byte)
	{
		ft_printf(ERROR_LINE, ERROR_LINE4, parse_champ->champion,
		parse_champ->line);
		return (0);
	}
	else if (mode == MODE_NULL && ((MAGIC_NULL >>
	(8 * (MAGIC_NULL_LENGTH - parse_champ->tmp_i - 1))) & 255) != byte)
	{
		ft_printf(ERROR_LINE, ERROR_LINE3, parse_champ->champion,
		parse_champ->line);
		return (0);
	}
	else if (mode == MODE_CODE)
		parse->champs[parse->pos - 1].code[parse_champ->tmp_i] = byte;
	return (1);
}

int			corewar_parse_line(t_parse *parse, t_parse_champ *parse_champ,
			const char *line, char mode)
{
	int 			ret;
	unsigned char	byte;
	unsigned int	length;

	static_length(parse, mode, &length);
	while (parse_champ->tmp_i < length)
	{
		if (!(ret = parse_byte(parse_champ, line, &byte)))
			return (0);
		if (ret == -1)
			return (1);
		if (!static_execute_mode(parse, parse_champ, mode, byte))
			return (0);
		parse_champ->tmp_i++;
	}
	static_update(parse, parse_champ, mode);
	if (mode == MODE_CODE && (line[parse_champ->i]
	|| parse_champ->tmp_i != parse->champs[parse->pos - 1].code_size))
	{
		ft_printf(ERROR_CHAMPION, ERROR_CHAMPION5, parse_champ->champion);
		return (0);
	}
	parse_champ->tmp_i = 0;
	return (1);
}
