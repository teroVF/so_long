/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:53:52 by antero            #+#    #+#             */
/*   Updated: 2023/05/19 03:14:34 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

/* ERROR MESSAGES */

# define MALLOC_ERR "malloc() failed"

# define MLX_INIT_ERR "Failed to initialize mlx"
# define MLX_NEW_WINDOW_ERR "Failed to open a new window"

/* CL arguments validation */
# define INVALID_NBR_ARGS "Invalid number of arguments"
# define NULL_MAP "NULL map argument"

/* Map validation */

# define INVALID_ENTITY "Invalid entity on map's file"
# define INVALID_FORMAT "Invalid map format"
# define INVALID_SETUP "Invalid number of Exits (E) or (P)"
# define NO_COLLECTIBLES "Map doesn't have any Collectible (C)"

# define UNACHIEVABLE_ENTITIES "Map has unachievable entities"

/* Reading map's content */

# define INVALID_MAP_FILE "Invalid map file extension"
# define OPEN_MAP_FILE_ERR "Failed to open map's file"
# define CLOSE_MAP_FILE_ERR "Failed to close map's file"
# define EMPTY_MAP_FILE "Map file is empty"

/* XPM Opening */

# define WALL_XPM_ERR "Failed to open wall image"
# define FLOOR_XPM_ERR "Failed to open floor image"
# define PLAYER_XPM_ERR "Failed to open player image"
# define COLLECTIBLE_XPM_ERR "Failed to open collectible image"
# define EXIT_XPM_ERR "Failed to open exit image"
# define FRIEND_XPM_ERR "Failed to open friend image"

#endif // ERROR_MESSAGES_H
