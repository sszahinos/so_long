/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:51:06 by sersanch          #+#    #+#             */
/*   Updated: 2023/03/06 16:36:44 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	map_get_columns(const char *map_path)
{
	int		i;
	int		map_fd;
	char	*row;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
	{
		close(map_fd);
		return (-1);
	}
	row = get_next_line(map_fd); //Free row al acabar?
	close(map_fd);
	i = 0;
	while (map[i] != '\n')
		if (map[i++] == '\0') //Solo hay 1 fila
			return (-1);
	return (i);
}

int map_get_rows(const char *map_path)
{
	int		map_fd;
	int		rows;
	char	*row;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
	{
		close(map_fd);
		return (-1);
	}
	rows = 0;
	while (1)
	{
		row = get_next_line(map_fd);
		if (!row) //free row?
		{
			close(map_fd);
			return (rows);
		}
		rows++;
	}
}

/* Input: 
 * 	map text
 * Output:
 * 	1 -> map has correct characters
 * 	0 -> map has forbidden characters
 */
int	check_map_characters(t_map map)
{
	int	*row_col[2];

	row_col[0] = 0;
	while (row_col[0] < map.rows)
	{
		row_col[1] = 0;
		while (row_col[1] < map.cols)
		{
			if (ft_strchr(ALLOWED_CHARS, map.map_arr[row_col[0]][row_col[1]]) == -1)
				return (-1);
			row_col[1]++;
		}
		row_col[0]++;
	}
	return (0);
}

/* Checks if the path has a rectangular map.
 * Input:
 * 	map path
 * Output:
 * 	-1 -> failed to open map 
 * 	1 -> map is rectangular
 * 	0 -> map is not rectangular
 */
int map_is_rectangular(const char *map_path)
{

	int		correct_rows;
	int		result;
	int		rows;
	int		cols;
	char	*row;

	correct_rows = 0;
	result = -1;
	cols = map_get_columns(map_path);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (-1);
	while (1)
	{
		row = get_next_line(map_fd);
		if (!row && correct_rows >= 5)
			result = 1;
		else if ((!row && correct_rows < 5) || (row[cols] != '\n' && row[cols] != '\0'))
			result = 0;
		correct_rows++;
		if (result != -1)
			break;
	}
	if (row)
		free(row);
	close(map_fd);
	return (result);
}

/* Transforms a char* map to t_map.
 * Input:
 * 	Map path
 * Output:
 * 	-1 -> Error opening the map
 * 	t_map -> Formatted map
 */
t_map *format_map(const char *map_path) //Se asume que se ha controlado que es correcto el mapa
{
	int 	map_fd;
	t_map	map;
	char	*row;

	map.rows = map_get_rows(map_path);
	map.cols = map_get_columns(map_path);
	map.map_arr = generate_2D_array(map.rows, map.cols);
	return (&map);
}

/* Input:
 * 	t_map map
 * Output:
 * 	0 -> Not surrounded by walls
 * 	1 -> Walls are correct.
 */

int	check_walls(t_map map)
{
	int	current_row;
	int	current_col;

	current_row = 0;
	while (current_row < map.rows)
	{
		if (current_row == 0 || current_row == map.rows) //si la primera o ultima fila es full 1
		{
			current_col = 0;
			while (current_col < map.cols)
			{
				if (map.map_arr[current_row][current_col] != ALLOWED_CHARS[1])
					return (0);
			}
			row_col[1]++;
		}
		else if (map.map_arr[current_row][0] != ALLOWED_CHARS[1] || map.map_arr[current_row][map.cols] != ALLOWED_CHARS[1])
			return (0);
		current_row++;
	}
	return (1);
}

//PONER EN LIBFT
char **generate_2D_array(int rows, int cols)
{
	char 	**arr_2d;
	int		i;

	arr_2d = malloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
		arr_2d[i++] = malloc(sizeof(char) * cols);
	return (arr_2d);
}
