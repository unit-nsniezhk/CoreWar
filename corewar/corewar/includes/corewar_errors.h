/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:07:19 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/29 21:21:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ERRORS_H

# define COREWAR_ERRORS_H

# define ERROR_OPTIONS "[redError:~] %s [yellow%u~]\n"
# define ERROR_OPTIONS2 "Redefinition of the -n option's value"
# define ERROR_OPTIONS3 "Redefinition of the -dump option's value"
# define ERROR_OPTIONS4 "Invalid value of the -dump option"
# define ERROR_OPTIONS5 "Invalid value of the -n option"
# define ERROR_OPTIONS6 "[redError:~] %s [yellow%Option %s~]\n"
# define ERROR_OPTIONS7 "Invalid symbol in the option's value"
# define ERROR_OPTIONS8 "[redError:~] Invalid position [yellowChampion #%u~]\n"
# define ERROR_OPTIONS9 "[redError:~] %s [yellow %s~]\n"
# define ERROR_OPTIONS10 "Invalid option"

# define ERROR_CHAMPION "[redError:~] %s [yellowChampion %s~]\n"
# define ERROR_CHAMPION2 "Specified position is invalid"
# define ERROR_CHAMPION3 "Can't open file of the champion"
# define ERROR_CHAMPION4 "Code of the champion is missing"
# define ERROR_CHAMPION5 "Wrong size of the champion's code"
# define ERROR_CHAMPION6 "[redError:~] %s %u [yellowChampion %s~]\n"
# define ERROR_CHAMPION7 "Code size is larger than"
# define ERROR_CHAMPION8 "[redError:~] %s [yellow%u~] %s\n"
# define ERROR_CHAMPION9 "Less than"
# define ERROR_CHAMPION10 "More than"
# define ERROR_CHAMPION11 "champions specified"

# define ERROR_LINE "[redError:~] %s [yellowChampion %s Line #%u~]\n"
# define ERROR_LINE2 "Empty line"
# define ERROR_LINE3 "Null is missing / incorrect"
# define ERROR_LINE4 "Magic header is missing / incorrect"
# define ERROR_LINE5 "Invalid symbol"
# define ERROR_LINE6 "Invalid number of bytes"

#endif
