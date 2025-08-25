/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/22 00:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * Valide que les murs du haut et du bas de la carte sont entièrement composés de '1'
 * Parcourt la première ligne (y=0) et la dernière ligne (y=height-1) pour vérifier
 * que chaque case contient un mur ('1')
 */
int	validate_top_bottom_walls(char **map, int width, int height)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

/**
 * Valide que les murs de gauche et de droite de la carte sont entièrement composés de '1'
 * Parcourt chaque ligne pour vérifier que la première colonne (x=0) et la dernière 
 * colonne (x=width-1) contiennent des murs ('1')
 */
int	validate_left_right_walls(char **map, int width, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

/**
 * Fonction principale de validation des bordures de la carte
 * Vérifie que la carte est entourée de murs ('1') sur tous les côtés
 * Contrôle aussi que la taille minimum (3x3) est respectée
 */
int	validate_map_borders(char **map)
{
	int	width;
	int	height;

	if (!map)
		return (0);
	width = get_map_width(map);
	height = get_map_height(map);
	if (width < 3 || height < 3)
		return (0);
	if (!validate_top_bottom_walls(map, width, height))
		return (0);
	if (!validate_left_right_walls(map, width, height))
		return (0);
	return (1);
}