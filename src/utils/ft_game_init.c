/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:19 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:19 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_image_init(t_game *game)
{
	game->img_0 = mlx_xpm_file_to_image(game->mlx, "./textures/0.xpm",
			&game->img_width, &game->img_height);
	game->img_1 = mlx_xpm_file_to_image(game->mlx, "./textures/1.xpm",
			&game->img_width, &game->img_height);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "./textures/C.xpm",
			&game->img_width, &game->img_height);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "./textures/E1.xpm",
			&game->img_width, &game->img_height);
	game->img_p = mlx_xpm_file_to_image(game->mlx, "./textures/PS.xpm",
			&game->img_width, &game->img_height);
}

static void	ft_window_init(t_game *game)
{
	int	i;

	game->width = (int)ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->height = i * 32;
}

void	ft_game_init(t_game *game)
{
	game->mlx = mlx_init();
	ft_window_init(game);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->moves_count = 0;
	game->endgame = 0;
	ft_image_init(game);
	ft_draw_map(game);
}
