/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:06 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:07 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *game)
{
	ft_free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_0);
	mlx_destroy_image(game->mlx, game->img_1);
	mlx_destroy_image(game->mlx, game->img_c);
	mlx_destroy_image(game->mlx, game->img_e);
	mlx_destroy_image(game->mlx, game->img_p);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}
