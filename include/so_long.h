/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:39 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:40 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define KEY_Q 113
# define KEY_ESC 65307

typedef struct s_config
{
	char	*p_line;
	// ---
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
}			t_config;

char		**ft_read_map(t_config *game, char *path);
int			ft_check_map(t_config *game);
int			ft_check_ext(char *argv);
void		ft_game_init(t_config *game);
int			ft_draw_map(t_config *game);
void		ft_game_play(t_config *game);
void		ft_move_left(t_config *game);
void		ft_move_right(t_config *game);
void		ft_move_down(t_config *game);
void		ft_move_up(t_config *game);
int			ft_path_is_valid(t_config *game);

// check
void		check_args(int argc, char **argv);

// parse
void		parse_file(char *filename);
void		parse_line(char *line);

// utils
t_config	*get_config(void);
void		init_config(void);
void		free_config(void);

int			has_extension(char *filename, char *extension);

int			ft_exit(char *error);

#endif
