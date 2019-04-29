/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_settings.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:12 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 22:37:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_SETTINGS_H

# define COREWAR_SETTINGS_H

# define MIN_PLAYERS 2
# define MAX_PLAYERS 4

# define BASE_MEM_SIZE 1024
# define MEM_SIZE MAX_PLAYERS * BASE_MEM_SIZE

# define CHAMP_MAX_SIZE MEM_SIZE / 6

# define CYCLE_TO_DIE 1536
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

//TODO below the line link from asm headers

//typedef char	t_arg_type;

#define REG_NUMBER 16

//# define T_REG 1
//# define T_DIR 2
//# define T_IND 4
//# define T_LAB 8

# define MAGIC_HEADER 0xea83f3
# define MAGIC_NULL 0

# define BYTES_PER_LINE 16

# define MAGIC_HEADER_LENGTH 4
# define CHAMPION_NAME_LENGTH 128
# define MAGIC_NULL_LENGTH 4
# define CODE_SIZE_LENGTH 4
# define CHAMPION_COMMENT_LENGTH 2048

#endif
