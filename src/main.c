/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:06:57 by sersanch          #+#    #+#             */
/*   Updated: 2023/02/22 15:53:56 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/mlx.h"

int	check_map_name(char *name)
{
	const char *extension = ".ber";
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name) - 1;
	while (i < 4)
	{
		if (name[len - i] != extension[3 - i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char** argv)
{
	if (argc != 2)
		ft_printf(ARGS_ERROR);
	else if (check_map_name(argv[1]))
		ft_printf(MAP_NAME_ERROR);
	else if (check_map_characters(argv[1]))
		ft_printf(MAP_CHARS_ERROR);
	else
		start_program
	argv[0][0] = 'a';
	return (0);
}
