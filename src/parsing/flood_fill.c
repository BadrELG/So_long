/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/15 15:09:35 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = g_malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				g_free(copy[i]);
			return (g_free(copy), NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_accessible(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_path(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				flood_fill(map_copy, j, i);
				break ;
			}
		}
	}
	i = check_accessible(map_copy);
	ft_tabstr_free(map_copy);
	return (i);
}
