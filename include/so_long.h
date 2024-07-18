/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <marvin@42porto.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:39 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:40 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_Q 113

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		rows;
	int		height;
	int		width;
	int		endgame;
	int		moves_count;
	int		c_count;
	int		e_count;
	int		p_count;
	int		p_pos_x;
	int		p_pos_y;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	int		img_height;
	int		img_width;
}			t_game;

void		ft_error(char *message);
char		**ft_read_map(t_game *game, char *path);
void		ft_free_map(char **map);
int			ft_check_map(t_game *game);
int			ft_check_ext(char *argv);
void		ft_game_init(t_game *game);
int			ft_draw_map(t_game *game);
void		ft_game_play(t_game *game);
int			ft_exit(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_up(t_game *game);
int			ft_path_is_valid(t_game *game);

#endif
