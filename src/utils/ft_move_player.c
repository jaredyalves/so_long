/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:15 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:15 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_player(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_p);
	if (key == 'w')
		game->img_p = mlx_xpm_file_to_image(game->mlx, "textures/PW.xpm",
				&game->img_width, &game->img_height);
	else if (key == 's')
		game->img_p = mlx_xpm_file_to_image(game->mlx, "textures/PS.xpm",
				&game->img_width, &game->img_height);
	else if (key == 'a')
		game->img_p = mlx_xpm_file_to_image(game->mlx, "textures/PA.xpm",
				&game->img_width, &game->img_height);
	else if (key == 'd')
		game->img_p = mlx_xpm_file_to_image(game->mlx, "textures/PD.xpm",
				&game->img_width, &game->img_height);
}

void	ft_move_up(t_game *game)
{
	ft_update_player('w', game);
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_pos_y + 1][game->p_pos_x] = '0';
		game->moves_count += 1;
		game->endgame = 1;
		ft_draw_map(game);
	}
	else if (game->map[game->p_pos_y][game->p_pos_x] == '1'
			|| game->map[game->p_pos_y][game->p_pos_x] == 'E')
		game->p_pos_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
			game->c_count -= 1;
		game->map[game->p_pos_y][game->p_pos_x] = 'P';
		game->map[game->p_pos_y + 1][game->p_pos_x] = '0';
		game->moves_count += 1;
		ft_draw_map(game);
	}
}

void	ft_move_down(t_game *game)
{
	ft_update_player('s', game);
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_pos_y - 1][game->p_pos_x] = '0';
		game->moves_count += 1;
		game->endgame = 1;
		ft_draw_map(game);
	}
	else if (game->map[game->p_pos_y][game->p_pos_x] == '1'
			|| game->map[game->p_pos_y][game->p_pos_x] == 'E')
		game->p_pos_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
			game->c_count -= 1;
		game->map[game->p_pos_y][game->p_pos_x] = 'P';
		game->map[game->p_pos_y - 1][game->p_pos_x] = '0';
		game->moves_count += 1;
		ft_draw_map(game);
	}
}

void	ft_move_left(t_game *game)
{
	ft_update_player('a', game);
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_pos_y][game->p_pos_x + 1] = '0';
		game->moves_count += 1;
		game->endgame = 1;
		ft_draw_map(game);
	}
	else if (game->map[game->p_pos_y][game->p_pos_x] == '1'
			|| game->map[game->p_pos_y][game->p_pos_x] == 'E')
		game->p_pos_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
			game->c_count -= 1;
		game->map[game->p_pos_y][game->p_pos_x] = 'P';
		game->map[game->p_pos_y][game->p_pos_x + 1] = '0';
		game->moves_count += 1;
		ft_draw_map(game);
	}
}

void	ft_move_right(t_game *game)
{
	ft_update_player('d', game);
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->c_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_pos_y][game->p_pos_x - 1] = '0';
		game->moves_count += 1;
		game->endgame = 1;
		ft_draw_map(game);
	}
	else if (game->map[game->p_pos_y][game->p_pos_x] == '1'
			|| game->map[game->p_pos_y][game->p_pos_x] == 'E')
		game->p_pos_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
			game->c_count -= 1;
		game->map[game->p_pos_y][game->p_pos_x] = 'P';
		game->map[game->p_pos_y][game->p_pos_x - 1] = '0';
		game->moves_count += 1;
		ft_draw_map(game);
	}
}
