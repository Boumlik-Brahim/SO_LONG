/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:44:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/18 16:14:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_draw_map(t_root *root, char *filename, int c, int r)
{
	root->imag.img = mlx_xpm_file_to_image(root->mlx, filename,
			&root->imag.img_w, &root->imag.img_h);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->imag.img,
		c * 32, 22 + r * 32);
	mlx_destroy_image(root->mlx, root->imag.img);
}

void	ft_put_mvnb(t_root *root, int i)
{
	char	*mvs;

	mvs = ft_itoa(i);
	mlx_string_put(root->mlx, root->mlx_win, 10, 0,
		0x00FFDC00, "MOUVEMENT NUMBER:");
	mlx_string_put(root->mlx, root->mlx_win, 180, 0, 0x00FFDC00, mvs);
	free (mvs);
}

void	ft_make_components(t_root *root, int c, int r)
{
	static int	i;

	mlx_clear_window(root->mlx, root->mlx_win);
	ft_put_mvnb(root, i++);
	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == '1')
				ft_draw_map(root, "xpmfiles_bonus/wood-plank.xpm", c, r);
			else if (root->map.data[r][c] == 'P')
				ft_draw_map(root, "xpmfiles_bonus/superhero.xpm", c, r);
			else if (root->map.data[r][c] == 'E')
				ft_draw_map(root, "xpmfiles_bonus/finish.xpm", c, r);
			else if (root->map.data[r][c] == 'C')
				ft_render_next_coll(root);
			else if (root->map.data[r][c] == 'D')
				ft_render_next_enemy(root);
			c++;
		}
		r++;
	}
}

void	ft_init(t_root *root)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	root->map.cols = ft_strlen(root->map.data[0]);
	root->map.rows = ft_rowlenght(root);
	ft_checkwalls (root);
	ft_checkchar (root);
	ft_checkvalid (root);
	root->mlx = mlx_init();
	root->mlx_win = mlx_new_window(root->mlx, root->map.cols * 32,
			(root->map.rows * 32) + 22, "so_long");
	ft_player_position (root);
	ft_make_components (root, c, r);
	mlx_loop_hook(root->mlx, ft_make_animation_components, root);
	mlx_hook (root->mlx_win, 2, 0, ft_key_hook, root);
	mlx_hook (root->mlx_win, 17, 0, ft_close_game, root);
	mlx_loop (root->mlx);
}
