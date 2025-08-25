/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/22 00:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * Compte les éléments essentiels de la carte : joueurs (P), sorties (E) et collectibles (C)
 * Parcourt toute la carte et incrémente les compteurs correspondants
 * Utilisé pour valider la logique du jeu (1 joueur, 1 sortie, au moins 1 collectible)
 */
void	count_map_elements(char **map, int *players, int *exits, int *collectibles)
{
	int	y;
	int	x;

	*players = 0;
	*exits = 0;
	*collectibles = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				(*players)++;
			else if (map[y][x] == 'E')
				(*exits)++;
			else if (map[y][x] == 'C')
				(*collectibles)++;
			x++;
		}
		y++;
	}
}

/**
 * Valide la logique de base du jeu sur la carte
 * Vérifie qu'il y a exactement 1 joueur (P), 1 sortie (E) et au moins 1 collectible (C)
 * Ces conditions sont nécessaires pour qu'une partie soit jouable
 */
int	validate_map_logic(char **map)
{
	int	players;
	int	exits;
	int	collectibles;

	if (!map)
		return (0);
	count_map_elements(map, &players, &exits, &collectibles);
	if (players != 1)
		return (0);
	if (exits != 1)
		return (0);
	if (collectibles < 1)
		return (0);
	return (1);
}