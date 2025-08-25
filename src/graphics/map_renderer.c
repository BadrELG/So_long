#include "../../so_long.h"

void render_map(t_game *game)
{
    int x, y;
    for (y = 0; y < game->height; y++)
    {
        for (x = 0; x < game->width; x++)
        {
            char tile = game->map[y][x];
            
            // Toujours afficher le sol d'abord (sauf pour les murs)
            if (tile != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.floor, x * TILE_SIZE, y * TILE_SIZE);
            
            // Puis afficher l'élément par-dessus
            if (tile == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.collect, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.player, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}