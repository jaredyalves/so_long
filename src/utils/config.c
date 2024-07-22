/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:06 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:07 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>

t_config	*get_config(void)
{
	static t_config	cfg;

	return (&cfg);
}

void	init_config(void)
{
	t_config	*cfg;

	cfg = get_config();
	cfg->p_line = NULL;
	cfg->width = -1;
	cfg->map = NULL;
	cfg->height = 0;
}

void	free_config(void)
{
	int			i;
	t_config	*cfg;

	i = -1;
	cfg = get_config();
	free(cfg->p_line);
	while (++i < cfg->height)
		free(cfg->map[i]);
	free(cfg->map);
	// mlx_destroy_image(cfg->mlx, cfg->img_0);
	// mlx_destroy_image(cfg->mlx, cfg->img_1);
	// mlx_destroy_image(cfg->mlx, cfg->img_c);
	// mlx_destroy_image(cfg->mlx, cfg->img_e);
	// mlx_destroy_image(cfg->mlx, cfg->img_p);
	// mlx_destroy_window(cfg->mlx, cfg->win);
	// mlx_destroy_display(cfg->mlx);
	// free(cfg->mlx);
}
