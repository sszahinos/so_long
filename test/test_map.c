/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:46:17 by sersanch          #+#    #+#             */
/*   Updated: 2023/03/06 18:07:24 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char** argv)
{
	t_map map;
	argc = 2;
	printf("Cols?> %d\n", map_get_columns(argv[1]));
	printf("Rows?> %d\n", map_get_rows(argv[1]));
	printf("Map is rectangular?> %d\n", map_is_rectangular(argv[1]));
	map = format_map(map_path);
	printf("Map formated:\n");
	print_map(map);
	printf("Check walls?> %d\n", check_walls(map));
	printf("Characaters OK?> %d\n", check_map_characters(map))
	return (0);
}
