/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:28:51 by badr              #+#    #+#             */
/*   Updated: 2025/10/03 20:39:42 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        return (1);
        
    // Initialiser la structure
    ft_memset(&game, 0, sizeof(t_game));
    
    // Charger la carte
    printf("1. debut main\n");
    game.map = read_map_file(argv[1]);
    game.width = get_map_width(game.map);
    game.height = get_map_height(game.map);
    // Après le chargement de la carte
    printf("2. carte chargee\n");

    // Valider la carte
    if (!validate_complete_map(game.map))
        error_exit("Carte invalide");
    printf("3. carte validee\n");

    setup_player_and_collectibles(&game);
    printf("4. joueur et collectibles configures\n");
    // Initialiser les graphiques
    init_graphics(&game);
    printf("5. graphiques initialises\n");

    // Dessiner la carte initiale AVANT la boucle
    render_map(&game);
    printf("6. carte rendue\n");

    // Lancer la boucle
    mlx_loop(game.mlx);
    
    return (0);
}

int validate_complete_map(char **map)
{
    if (!validate_map_characters(map))
        return (0);
    if (!validate_map_shape(map))
        return (0);
    if (!validate_map_borders(map))
        return (0);
    if (!validate_map_logic(map))
        return (0);
    return (1);
}

void setup_player_and_collectibles(t_game *game)
{
    int y;
    int x;
    int players;
    int exits;
    int collectibles; 

    y = 0;
    count_map_elements(game->map, &players, &exits, &collectibles);
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                break;
            }
            x++;
        }
        y++;
    }
    game->collectibles = collectibles;
}
