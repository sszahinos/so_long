/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:51:06 by sersanch          #+#    #+#             */
/*   Updated: 2023/03/06 15:34:56 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Input: 
 * 	map text
 * Output:
 * 	0 -> map has correct characters
 * 	1 -> map has forbidden characters
 */
int	check_map_characters(char **map)
{
	char	*line;
	int		i;
	
	while (1)
	{
		line = get_next_line(map);
		if (!line)
			break;
		i = 0;
		while (line[i])
		{
			if (ft_strchr(ALLOWED_CHARS, line[i]) == -1)
				return (1);
			i++;
		}
	}
	return (0);
}

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

t_map *format_map(const char *map_path) //Se asume que se ha controlado que es correcto el mapa
{
	int 	map_fd;
	t_map	map;
	char	*row;

	map.rows = map_get_rows(map_path);
	map.cols = map_get_columns(map_path);
	map.map_arr = generate_2D_array(map.rows, map.cols);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
	{
		close(map_fd);
		return (NULL);
	}
	while (1)
	{
		row = get_next_line(map_fd);
		if (!row) // free row? controlar que tenga mínimo 5 rows (3x3 interior)?
		{
			close(map_fd);
			return (1);
		}
		if (row[cols] != '\n' || row[cols] != '\0')
			return (0);
	}
	return (&map);
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
