#include "../../so_long.h"

int load_sprites(t_game *game)
{

    int img_width, img_height;  // Variables pour les dimensions des sprites
    
    game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "textures/Wall.xpm", &img_width, &img_height);
    game->sprites.floor = mlx_xpm_file_to_image(game->mlx, "textures/Floor.xpm", &img_width, &img_height);
    game->sprites.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &img_width, &img_height);
    game->sprites.collect = mlx_xpm_file_to_image(game->mlx, "textures/Collectible.xpm", &img_width, &img_height);
    game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &img_width, &img_height);
    if (!game->sprites.wall || !game->sprites.floor || !game->sprites.player || !game->sprites.collect || !game->sprites.exit)
        return (0);
    return (1);
}

void free_sprites(t_game *game)
{
    if (game->sprites.wall)
        mlx_destroy_image(game->mlx, game->sprites.wall);
    if (game->sprites.floor)
        mlx_destroy_image(game->mlx, game->sprites.floor);
    if (game->sprites.player)
        mlx_destroy_image(game->mlx, game->sprites.player);
    if (game->sprites.collect)
        mlx_destroy_image(game->mlx, game->sprites.collect);
    if (game->sprites.exit)
        mlx_destroy_image(game->mlx, game->sprites.exit);
}