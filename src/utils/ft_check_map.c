/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:06 by jcapistr          #+#    #+#             */
/*   Updated: 2023/06/12 13:18:06 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_retangular(t_config *game)
{
	int	i;

	i = 1;
	if (game->map == NULL)
		return (0);
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_around_wall(t_config *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->map[i] == NULL)
		return (0);
	while (game->map[i] != NULL)
		i++;
	while (game->map[0][j] != '\0' && game->map[i - 1][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	j = (int)ft_strlen(game->map[i]);
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_pec(t_config *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->p_count += 1;
				game->p_pos_y = i;
				game->p_pos_x = j;
			}
			else if (game->map[i][j] == 'E')
				game->e_count += 1;
			else if (game->map[i][j] == 'C')
				game->c_count += 1;
		}
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count == 0)
		return (0);
	return (1);
}

static int	ft_is_valid(t_config *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'C' && game->map[i][j] != '0' &&
				game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map(t_config *game)
{
	if (ft_is_retangular(game) && ft_is_around_wall(game) && ft_is_pec(game)
		&& ft_is_valid(game) && ft_path_is_valid(game))
		return (1);
	return (0);
}
