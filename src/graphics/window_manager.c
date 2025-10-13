/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/04 15:28:05 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * Gère les événements clavier
 * ESC (code 53) pour quitter le jeu
 * Autres touches pour les mouvements (implémentation future)
 */
int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53) // Touche ESC
	{
		close_game(game);
	}
	return (0);
}

/**
 * Gère la fermeture de la fenêtre avec la croix rouge
 * Appelée automatiquement quand l'utilisateur clique sur la croix
 */
int	close_hook(t_game *game)
{
	close_game(game);
	return (0);
}

/**
 * Ferme proprement le jeu
 * Libère les sprites, détruit la fenêtre et quitte
 */
void	close_game(t_game *game)
{
	if (game && game->mlx)
	{
		if (game->win)
		{
			free_sprites(game);
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		// Ne pas détruire mlx car ça peut causer des crashes
		game->mlx = NULL;
	}
	garbage_destroy();
	exit(0);
}

/**
 * Configure tous les hooks MLX pour la gestion des événements
 * Doit être appelée après la création de la fenêtre
 */
/**
 * Boucle de jeu principale
 * Appelée à chaque frame par mlx_loop_hook
 * Pour l'instant, on ne fait rien ici car le rendu est fait uniquement
 * lors des mouvements pour économiser les ressources CPU
 */
int	game_loop(t_game *game)
{
	// Ne rien faire - le rendu se fait uniquement lors des mouvements
	// Cela évite de redessiner inutilement la carte à chaque frame
	(void)game;
	return (0);
}

/**
 * Configure tous les hooks MLX pour la gestion des événements
 * Doit être appelée après la création de la fenêtre
 */
void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_hook, game); // 17 = DestroyNotify (croix rouge)
	mlx_loop_hook(game->mlx, game_loop, game);
}
