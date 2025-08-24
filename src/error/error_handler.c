/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/08/22 00:00:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *message)
{
	if (message)
		ft_putstr_fd(message, 2);
	garbage_destroy();
	exit(1);
}

void	error_free_and_exit(char **map, char *message)
{
	if (map)
	{
		while (*map)
		{
			g_free(*map);
			map++;
		}
		g_free(map);
	}
	error_exit(message);
}