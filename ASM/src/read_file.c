/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:22:39 by amartyne          #+#    #+#             */
/*   Updated: 2019/04/16 15:22:42 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdio.h"

void	remember_name(t_file *file, t_all *info, int key)
{
	int		i;
	char	*tmp;
	int 	quotes;

	quotes = 0;
	if (key == 1 && info->is_name == 1)
		print_err(1, file->n, 1);
	else if(key == 2 && info->is_comment == 1)
		print_err(2, file->n, 1);
	i = -1;
	while (file->line[++i] != '\0')
		if (file->line[i] == 34)
			quotes++;
	if (quotes == 0 && (key == 1 || key == 2))
		print_err(4, file->n, --i);
	if (quotes != 2 && key == 1)
		print_err(1, file->n, --i);
	else if (quotes != 2 && key == 2)
		print_err(2, file->n, --i);
	tmp = ft_strchr(file->line, 34);
	tmp++;
	while (tmp[i] && tmp[i] != 34)
		i++;
	if (key == 1)
	{
		info->champion_name = ft_strsub(tmp, 0, i);
		info->is_name = 1;
	}
	else if (key == 2)
	{
		info->comment = ft_strsub(tmp, 0, i);
		info->is_comment = 1;
	}
}

void    check_line(t_file *file, t_all *info)
{
    int 	i;
    char	*admit;
	char 	*rest;

    if (ft_strncmp(file->line, NAME_CMD_STRING, 5) == 0)
    	remember_name(file, info, 1);
	else if (ft_strncmp(file->line, COMMENT_CMD_STRING, 8) == 0)
		remember_name(file, info, 2);
	else
	{
		admit = cut_instruction(file->line, &rest);
		printf("rest %s\n", rest);
		i = -1;
		while (++i < NUMB_INSTRUCTION)
		{
			if (ft_strcmp(admit, op_tab[i].instruction) == 0)
				info->number_tokens += op_tab[i].number_arg + 1;
		}
	}
}

void    write_info(t_all *info, t_file *file)
{
    int		i;
    char	*admit;
    char 	*rest;
    int 	cmp;

    i = 0;
    cmp = 1;
    while (file && file->next)
    {
		admit = cut_instruction(file->line, &rest);
		while (i < NUMB_INSTRUCTION && cmp != 0)
		{
			cmp = ft_strcmp(admit, op_tab[i].instruction);
			i++;
		}
        if (cmp == 0)
        {
            info->tokens[info->n].name = ft_strdup(op_tab[--i].instruction);
			printf("T_N %d, %s ", info->n, info->tokens[info->n].name);
            info->tokens[info->n++].token = INSTRUCTION;
			printf("%d\n", info->n);
			cut_last(rest, info);
        }
        i = 0;
        cmp = 1;
        file = file->next;
    }
}

void    read_file_asm(char **av)
{
    int		fd;
    t_file	*file;
    t_file	*buf;
    t_all   info;
    int		i;

    i = 1;
    info.number_tokens = 0;
    info.tokens = NULL;
    info.n = 0;
    fd = open(av[1], O_RDONLY);
    info.filename = cut_filename(av[1]);
    file = (t_file*)malloc(sizeof(t_file));
    file->line = NULL;
    file->n = i++;
    file->next = NULL;
    buf = file;
    while (get_next_line(fd, &file->line))
    {
        if (ft_strlen(file->line))
			check_line(file, &info);
        file->next = (t_file*)malloc(sizeof(t_file));
        file = file->next;
		file->n = i++;
        file->next = NULL;
    }
//	ft_printf("NAME \"%s\"\n", info.champion_name);
//	ft_printf("COMMENT \"%s\"\n", info.comment);
    ft_printf("NUMBER_TOKENS %d\n", info.number_tokens);
//	ft_printf("FILENAME %s\n", info.filename);
    info.tokens = (t_code*)malloc(sizeof(t_code) * info.number_tokens);
    write_info(&info, buf);
    validation(&info);
}