/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:08:27 by sersanch          #+#    #+#             */
/*   Updated: 2023/02/22 14:09:09 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ALLOWED_CHARS = "01CEP"
# define ARGS_ERROR = "Error\nOnly one argument required.\n"
# define MAP_NAME_ERROR = "Error\nThe map must have \".ber\" extension.\n"
# define MAP_CHARS_ERROR = "Error\nThe map has wrong characters.\n"
# define MAP_RECTANGULAR_ERROR = "Error\nThe map is not rectangular or too small\n"

typedef struct s_map
{
	char	**map_arr;
	int		cols;
	int		rows;

} t_map;

#endif
