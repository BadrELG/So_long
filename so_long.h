#include "mlx.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
} t_game;

/* ************************************************************************** */
/*                               PROTOTYPES                                  */
/* ************************************************************************** */

/* Parsing functions */
char    **read_map_file(char *filename);
char    **create_map_array(t_list *lines);
int     is_valid_line(char *line);

/* Validation functions */
int     is_valid_character(char c);
int     validate_map_characters(char **map);
int     get_map_width(char **map);
int     get_map_height(char **map);
int     validate_map_shape(char **map);

/* Border validation functions */
int     validate_top_bottom_walls(char **map, int width, int height);
int     validate_left_right_walls(char **map, int width, int height);
int     validate_map_borders(char **map);

/* Logic validation functions */
void    count_map_elements(char **map, int *players, int *exits, int *collectibles);
int     validate_map_logic(char **map);

/* Error handling functions */
void    error_exit(char *message);
void    error_free_and_exit(char **map, char *message);
