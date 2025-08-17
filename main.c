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

#include "mlx/mlx.h"

int main(void)
{
    void *mlx;
   // void *exp;
    
    mlx = mlx_init();  // Établit connexion au système graphique
    mlx_new_window(mlx, 1920, 1080, "Hello world!");  // Crée fenêtre
    mlx_loop(mlx);     // Lance le rendu de la fenêtre
}
