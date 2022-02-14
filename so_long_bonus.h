/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:41:36 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/14 21:09:38 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <fcntl.h>
# include "./Libft/libft.h"

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_w;
	int		img_h;
}t_img;

typedef struct s_player{
	int	x;
	int	y;
}t_player;

typedef struct s_map{
	char	**data;
	int		cols;
	int		rows;
	int		player;
	int		collectible;
	int		exit;
	int		enemy;
}t_map;

typedef struct s_root{
	void		*mlx;
	void		*mlx_win;
	t_img		imag;
	t_player	player;
	t_map		map;
}t_root;

void	ft_free_map(t_root *root);
char	*ft_read_file(int fd);
char	**ft_return_map(char *file, int *i);
void	ft_read_map(char *file, t_root	*root);

void	ft_check_map_ext(char *av, t_root *root);
void	ft_checkwalls(t_root *root);
void	ft_checkchar(t_root *root);
void	ft_checkvalid(t_root *root);

int		ft_rowlenght(t_root *root);
void	ft_map_errors(t_root *root, char *s);

void	ft_draw_map(t_root *root, char *filename, int c, int r);
void	ft_put_mvnb(t_root *root, int i);
void	ft_make_components(t_root *root, int c, int r);
void	ft_init(t_root *root);

int		ft_key_hook(int keycode, t_root *root);

void	ft_player_position(t_root *root);

void	ft_coll_position(t_root *root, char *path);
int		ft_render_next_coll(t_root *root);
int		ft_make_animation_components(t_root *root);

void	ft_enemie_position(t_root *root, char *path);
int		ft_render_next_enemy(t_root *root);

void	ft_move_left(t_root *root);
void	ft_move_right(t_root *root);
void	ft_move_up(t_root *root);
void	ft_move_down(t_root *root);

int		ft_close_game(t_root *root);
int		ft_exit_game(t_root *root, char *msg, char color);

#endif