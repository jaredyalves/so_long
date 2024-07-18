/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:42:44 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->p_pos_y -= 1;
		ft_move_up(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->p_pos_y += 1;
		ft_move_down(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->p_pos_x -= 1;
		ft_move_left(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->p_pos_x += 1;
		ft_move_right(game);
	}
}

static int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		ft_exit(game);
	if (game->endgame == 0)
	{
		ft_events(keycode, game);
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(game->moves_count, 1);
		ft_putstr_fd("\n", 1);
		if (game->endgame == 1)
		{
			ft_putstr_fd("Thank you for playing. Bye.\n", 1);
			ft_exit(game);
		}
	}
	return (0);
}

void	ft_game_play(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, ft_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, ft_exit, game);
	mlx_hook(game->win, 9, 1L << 21, ft_draw_map, game);
}
