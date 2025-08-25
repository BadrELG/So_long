#include "../../so_long.h"

/**
 * Lit et parse un fichier de carte (.ber)
 * Ouvre le fichier, lit ligne par ligne avec get_next_line
 * Valide chaque ligne et stocke dans une liste chaînée
 * Convertit finalement la liste en tableau de chaînes
 */
char **read_map_file(char *filename)
{
    int     fd;
    t_list  *lines;
    char    *line;
    char    **map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error\nFailed to open map file\n");
    lines = NULL;
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        error_exit("Error\nEmpty map file\n");
    }
    while (line)
    {
        if (!is_valid_line(line))
        {
            close(fd);
            ft_lstclear(&lines, NULL);
            error_exit("Error\nInvalid line in map\n");
        }
        ft_lstadd_back(&lines, ft_lstnew(line));
        line = get_next_line(fd);
    }
    close(fd);
    map = create_map_array(lines);
    ft_lstclear(&lines, NULL);
    return (map);
}

/**
 * Convertit une liste chaînée de lignes en tableau de chaînes de caractères
 * Alloue la mémoire nécessaire pour le tableau et copie chaque ligne
 * Le tableau est terminé par NULL pour faciliter les parcours
 */
char **create_map_array(t_list *lines)
{
    int     count;
    char    **map;
    t_list  *current;
    int     i;

    if (!lines)
        error_exit("Error\nNo valid lines found\n");
    count = ft_lstsize(lines);
    if (count == 0)
        error_exit("Error\nEmpty map\n");
    map = g_malloc((count + 1) * sizeof(char *));
    if (!map)
        error_exit("Error\nMemory allocation failed\n");
    current = lines;
    i = 0;
    while (i < count)
    {
        map[i] = current->content;
        current = current->next;
        i++;
    }
    map[count] = NULL;
    return (map);
}

/**
 * Vérifie qu'une ligne lue du fichier est valide
 * Contrôle que la ligne n'est pas vide (longueur > 1)
 * Vérifie que la ligne se termine par '\n' (sauf pour la dernière ligne)
 */
int is_valid_line(char *line)
{
    int len;

    if (!line)
        return (0);
    len = ft_strlen(line);
    if (len <= 1)
        return (0);
    return (1);
}