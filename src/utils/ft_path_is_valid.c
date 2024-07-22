/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:09:59 by jcapistr          #+#    #+#             */
/*   Updated: 2023/06/12 13:41:15 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_path(t_config *game, int x, int y, char **path)
{
	static int	coins = 0;
	static int	has_exit = 0;

	if (path[y][x] == '1')
		return (0);
	else if (path[y][x] == 'C')
		coins += 1;
	else if (path[y][x] == 'E')
	{
		has_exit = 1;
		return (0);
	}
	path[y][x] = '1';
	ft_check_path(game, x + 1, y, path);
	ft_check_path(game, x - 1, y, path);
	ft_check_path(game, x, y + 1, path);
	ft_check_path(game, x, y - 1, path);
	return (coins == game->c_count && has_exit);
}

static void	ft_delete(char **matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_path_is_valid(t_config *game)
{
	char	**tmp;
	int		i;
	int		is_valid;

	i = 0;
	tmp = (char **)ft_calloc(sizeof(char *), game->rows + 1);
	if (tmp == NULL)
		return (0);
	while (i < game->rows)
	{
		tmp[i] = ft_strdup(game->map[i]);
		if (tmp[i] == NULL)
		{
			ft_delete(tmp);
			return (0);
		}
		i++;
	}
	is_valid = ft_check_path(game, game->p_pos_x, game->p_pos_y, tmp);
	ft_delete(tmp);
	return (is_valid);
}
