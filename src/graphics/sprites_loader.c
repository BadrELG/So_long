#include "../../so_long.h"


// retirer printf
int load_sprites(t_game *game)
{
    int img_width, img_height;
    
    printf("Chargement des sprites...\n");
    
    game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "textures/Wall.xpm", &img_width, &img_height);
    printf("Wall sprite: %p\n", game->sprites.wall);
    
    game->sprites.floor = mlx_xpm_file_to_image(game->mlx, "textures/Floor.xpm", &img_width, &img_height);
    printf("Floor sprite: %p\n", game->sprites.floor);
    
    game->sprites.player = mlx_xpm_file_to_image(game->mlx, "textures/player_64.xpm", &img_width, &img_height);
    printf("Player sprite: %p\n", game->sprites.player);
    
    game->sprites.collect = mlx_xpm_file_to_image(game->mlx, "textures/Collectible_64.xpm", &img_width, &img_height);
    printf("Collectible sprite: %p\n", game->sprites.collect);
    
    game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_64.xpm", &img_width, &img_height);
    printf("Exit sprite: %p\n", game->sprites.exit);
    
    if (!game->sprites.wall || !game->sprites.floor || !game->sprites.player || 
        !game->sprites.collect || !game->sprites.exit)
    {
        printf("ERREUR: Un ou plusieurs sprites n'ont pas pu être chargés!\n");
        return (0);
    }
    printf("Tous les sprites chargés avec succès\n");
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