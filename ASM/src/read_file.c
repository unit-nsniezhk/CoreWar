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

void    check_line(char *line, t_all *info)
{
    int i;
    int number;

    number = info->number_tokens;
    i = -1;
    while (++i < NUMB_INSTRUCTION)
    {
        if (ft_strcmp(line, op_tab[i]) == 0)
            info->number_tokens++;
    }
    if (number + 1 != info->number_tokens)
        print_error(3);
}

void    write_info(t_all *info, t_file *file)
{
    int i;

    i = -1;
    while (file && file->line)
    {
        if (ft_strcmp(line, op_tab[i]) == 0)
        {
            info->tokens->name = op_tab[i];
            info->tokens->token = 2;
        }
        file = file->next;
    }
}

void    read_file(char **av)
{
    int fd;
    t_file *file;
    t_file *buf;
    t_all   info;

    info = malloc(sizeof(t_all));
    info.number_tokens = 0;
    info.tokens = NULL;
    fd = open(av[1], O_RDONLY);
    file = (t_file*)malloc(sizeof(t_file));
    file->next = NULL;
    buf = file;
    while (get_next_line(fd, &file->line))
    {
        file->next = (t_file*)malloc(sizeof(t_file));
        ft_printf("%s\n", file->line);
        file = file->next;
        file->next = NULL;
    }
    info.tokens = (t_code*)malloc(sizeof(t_code) * info.number_tokens);
    write_info(&info, buf);
}