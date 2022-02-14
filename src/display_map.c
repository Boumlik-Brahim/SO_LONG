/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:44:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/18 16:10:51 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_draw_map(t_root *root, char *filename, int c, int r)
{
	root->imag.img = mlx_xpm_file_to_image(root->mlx, filename,
			&root->imag.img_w, &root->imag.img_h);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->imag.img,
		c * 32, r * 32);
	mlx_destroy_image(root->mlx, root->imag.img);
}

void	ft_make_components(t_root *root, int c, int r)
{
	static int	i;

	printf("\033[1;5;92MOUVEMENT NUMBER:%d\n", i++);
	mlx_clear_window(root->mlx, root->mlx_win);
	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == '1')
				ft_draw_map(root, "xpmfiles/wood-plank.xpm", c, r);
			else if (root->map.data[r][c] == 'P')
				ft_draw_map(root, "xpmfiles/superhero.xpm", c, r);
			else if (root->map.data[r][c] == 'E')
				ft_draw_map(root, "xpmfiles/finish.xpm", c, r);
			else if (root->map.data[r][c] == 'C')
				ft_draw_map(root, "xpmfiles/bitcoin.xpm", c, r);
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
	ft_checkvalid(root);
	root->mlx = mlx_init();
	root->mlx_win = mlx_new_window(root->mlx, root->map.cols * 32,
			root->map.rows * 32, "so_long");
	ft_player_position (root);
	ft_make_components (root, c, r);
	mlx_hook (root->mlx_win, 2, 0, ft_key_hook, root);
	mlx_hook (root->mlx_win, 17, 0, ft_close_game, root);
	mlx_loop (root->mlx);
}
