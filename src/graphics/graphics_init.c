#include "../../so_long.h"

void init_graphics(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit("Failed to initialize graphics");
    game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So Long");
    if (!game->win)
        error_exit("Failed to create window");
    if (!load_sprites(game))
        error_exit("Failed to load sprites");
    setup_hooks(game);
}
