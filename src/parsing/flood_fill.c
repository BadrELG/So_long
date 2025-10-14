/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/14 16:46:22 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**copy_map(char **map)
{
	int		height;
	int		i;
	char	**copy;

	if (!map)
		return (NULL);
	height = 0;
	while (map[height])
		height++;
	copy = (char **)malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	flood_fill(char **map_copy, int x, int y, int *collectibles, int *exit_found)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'X')
		return ;
	if (map_copy[y][x] == 'C')
		(*collectibles)++;
	if (map_copy[y][x] == 'E')
		(*exit_found) = 1;
	map_copy[y][x] = 'X';
	flood_fill(map_copy, x + 1, y, collectibles, exit_found);
	flood_fill(map_copy, x - 1, y, collectibles, exit_found);
	flood_fill(map_copy, x, y + 1, collectibles, exit_found);
	flood_fill(map_copy, x, y - 1, collectibles, exit_found);
}

static void	find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	validate_path(char **map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		collectibles_found;
	int		exit_found;
	int		total_collectibles;
	int		players;
	int		exits;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	find_player_position(map, &player_x, &player_y);
	count_map_elements(map, &players, &exits, &total_collectibles);
	collectibles_found = 0;
	exit_found = 0;
	flood_fill(map_copy, player_x, player_y, &collectibles_found, &exit_found);
	free_map(map_copy);
	if (collectibles_found == total_collectibles && exit_found)
		return (1);
	return (0);
}
