/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/14 16:28:42 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * Vérifie qu'un caractère est autorisé dans la carte
 * Caractères valides : '0' (espace libre), '1' (mur), 'C' (collectible), 
 * 'E' (sortie), 'P' (joueur), '\n' (retour à la ligne)
 */
int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	validate_map_characters(char **map)
{
	int	y;
	int	x;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_valid_character(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/**
 * Calcule la largeur de la carte en caractères
 * Gère automatiquement la présence ou l'absence du \n
 */
int	get_map_width(char **map)
{
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	if (len > 0 && map[0][len - 1] == '\n')
		return (len - 1);
	return (len);
}

int	get_map_height(char **map)
{
	int	height;

	if (!map)
		return (0);
	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	validate_map_shape(char **map)
{
	int	width;
	int	height;
	int	y;
	int	current_width;

	if (!map)
		return (0);
	width = get_map_width(map);
	height = get_map_height(map);
	if (width < 3 || height < 3)
		return (0);
	y = 0;
	while (map[y])
	{
		current_width = ft_strlen(map[y]);
		if (current_width > 0 && map[y][current_width - 1] == '\n')
			current_width--;
		if (current_width != width)
			return (0);
		y++;
	}
	return (1);
}