/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:28:51 by badr              #+#    #+#             */
/*   Updated: 2025/07/29 22:01:08 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *dot = ft_strrchr(argv[1], '.');
        if (!dot || ft_strncmp(dot, ".ber", 4) != 0)
        {
            printf("Le fichier n'est pas un fichier .ber\n");
            return (1);
        }
        
        void *mlx;
       // void *exp;
        mlx = mlx_init();  // Établit connexion au système graphique
        mlx_new_window(mlx, 1920, 1080, "Hello world!");  // Crée fenêtre
        mlx_loop(mlx);     // Lance le rendu de la fenêtre
        /* code */
    }
    else {
        printf("error\n");
        return (1);
    }
    return (0);
}
