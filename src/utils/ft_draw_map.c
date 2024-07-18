/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:12 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:43:24 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_image(t_game *game, void *image, int x, int y)
{
	if (image != NULL)
		mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
	else
		ft_error("Image could not be loaded.\n");
}

static void	ft_draw_player(t_game *game, void *image, int x, int y)
{
	game->p_pos_x = x;
	game->p_pos_y = y;
	ft_draw_image(game, image, x, y);
}

static void	ft_draw_exit(t_game *game, int x, int y)
{
	if (game->c_count == 0)
	{
		mlx_destroy_image(game->mlx, game->img_e);
		game->img_e = mlx_xpm_file_to_image(game->mlx, "./textures/E2.xpm",
				&game->img_width, &game->img_height);
	}
	ft_draw_image(game, game->img_e, x, y);
}

int	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1')
				ft_draw_image(game, game->img_1, x, y);
			else if (game->map[y][x] == '0')
				ft_draw_image(game, game->img_0, x, y);
			else if (game->map[y][x] == 'P')
				ft_draw_player(game, game->img_p, x, y);
			else if (game->map[y][x] == 'C')
				ft_draw_image(game, game->img_c, x, y);
			else if (game->map[y][x] == 'E')
				ft_draw_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
