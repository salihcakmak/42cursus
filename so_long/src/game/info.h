/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:08:04 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 01:51:55 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

/* tag define */
# define SYS_TAG "[System Message]"
# define ERR_TAG "[ERROR Message]"

/* solong */
# define INIT_ERR "Solong not initialized\n"
# define ARG_ERROR "Wrong number of arguments"

/* file define */
# define FOPN_ERROR "The file could not be opened.No such file or directory\n"
# define FCLS_ERROR "Could not be closed. Bad file descriptor\n"
# define FNAME_ERROR "File name too short"
# define BER_ERROR "'.ber' extension not found"

/* map control define */
# define NULL_MAP "NULL MAP"
# define EMPTY_FILE "Map file is empty\n"
# define ONLY_NL "Map file contains only new line\n"
# define WALL_ERR "The wall contains gaps\n"
# define RECTANGLE_ERR "The map is not rectangular\n"
# define ELEMENT_ERR "Map elements are missing\n"
# define O_ELEMENT_ERR "Map contains external elements\n"
# define DUB_PLAYER_ERR "Multiple players\n"

/* memory define (malloc) */
# define NOT_ALLOCATED "Memory could not be allocated\n"
# define ALLOCATED "Memory allocated.\n"

# define ESC_EXIT "Logout Successfull\n"
# define GAME_OVER "All Bitcoins Collected. YOU ARE RICH NOW\n"
#endif