/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:51:06 by sersanch          #+#    #+#             */
/*   Updated: 2023/02/22 17:45:29 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	map_is_rectangular(char **map)
{
	
}

char **format_array_map(char **map)
{
	char	**formated_map;
	char	**aux;
	char	*line;
	int		i;

	formated_map = NULL;
	while (1)
	{
		line = get_next_line(map);
		if (!line)
			break;
		aux = formated_map;
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
