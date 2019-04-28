/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:01:16 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/28 22:06:36 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	parse_byte(t_parse *parse, const char *line, unsigned char *byte)
{
	while (line[parse->i] == ' ')
		parse->i++;
	if (!line[parse->i])
		return (-1);
	if (!ft_strin(HEX, line[parse->i]))
	{
		ft_printf("error");
		return (0);
	}
	if (parse->bytes == MAX_BYTES_PER_LINE)
	{
		ft_printf("err");
		return (0);
	}
	*byte = (char)ft_antouibase(HEX, &line[parse->i], 2);
	if (ft_strin(HEX, line[parse->i]))
		parse->i++;
	parse->bytes++;
	return (1);
}

static void	static_update(t_parse *parse, char mode)
{
	if (mode == MODE_NAME)
		parse->name = 1;
	else if (mode == MODE_MAGIC_HEADER)
		parse->magic_header = 1;
	else if (mode == MODE_NULL)
	{
		if (!parse->first_null)
			parse->first_null = 1;
		else
			parse->second_null = 1;
	}
	else if (mode == MODE_CODE_SIZE)
		parse->code_size = 1;
	else if (mode == MODE_COMMENT)
		parse->comment = 1;
}

static void	static_get_length(t_parse *parse, char mode, unsigned int *length)
{
	if (mode == MODE_NAME)
		*length = PROG_NAME_LENGTH;
	else if (mode == MODE_MAGIC_HEADER)
		*length = MAGIC_HEADER_LENGTH;
	else if (mode == MODE_NULL)
		*length = NULL_LENGTH;
	else if (mode == MODE_CODE_SIZE)
		*length = CODE_SIZE_LENGTH;
	else if (mode == MODE_COMMENT)
		*length = COMMENT_LENGTH;
	else if (mode == MODE_CODE)
		*length = parse->code_size;
}

static int	static_execute_mode(t_parse *parse, char mode, unsigned char byte)
{
	if (mode == MODE_NAME)
		parse->champs[parse->pos - 1].name[parse->tmp_i] = byte;
	else if (mode == MODE_COMMENT)
		parse->champs[parse->pos - 1].comment[parse->tmp_i] = byte;
	else if (mode == CODE_SIZE_LENGTH)
		parse->champs[parse->pos - 1].code_size =
		parse->champs[parse->pos - 1].code_size << 8 | (unsigned int)byte;
	else if (mode == MODE_MAGIC_HEADER && ((COREWAR_EXEC_MAGIC >>
	(8 * (MAGIC_HEADER_LENGTH - parse->tmp_i - 1))) & 255) != byte)
	{
		ft_printf("error");
		return (0);
	}
	else if (mode == MODE_NULL
	&& ((COREWAR_NULL >> (8 * (NULL_LENGTH - parse->tmp_i - 1))) & 255) != byte)
	{
		ft_printf("error not the same ;)");
		return (0);
	}
	else if (mode == MODE_CODE)
		parse->champs[parse->pos - 1].code[parse->tmp_i] = byte;
	return (1);
}

int			corewar_parse_line(t_parse *parse, const char *line, char mode)
{
	int 			ret;
	unsigned char	byte;
	unsigned int	length;

	static_get_length(parse, mode, &length);
	while (parse->tmp_i < length)
	{
		if (!(ret = parse_byte(parse, line, &byte)))
			return (0);
		if (ret == -1)
			return (1);
		if (!static_execute_mode(parse, mode, byte))
			return (0);
		parse->tmp_i++;
	}
	static_update(parse, mode);
	parse->tmp_i = 0;
	return (1);
}
