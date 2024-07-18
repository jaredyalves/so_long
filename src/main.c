/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		game.map = ft_read_map(&game, argv[1]);
		if (ft_check_map(&game) && ft_check_ext(argv[1]))
		{
			ft_game_init(&game);
			ft_game_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				ft_free_map(game.map);
			ft_error("The map is not valid.\n");
		}
	}
	else
		ft_error("You must provide a map.\n");
	return (0);
}
