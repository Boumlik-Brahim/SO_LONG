/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_eni_mation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:33:46 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 10:52:17 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_coll_position(t_root	*root, char	*path)
{
	static int	r;
	static int	c;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == 'C')
				ft_draw_map(root, path, c, r);
			c++;
		}
		r++;
	}
}

int	ft_render_next_coll(t_root	*root)
{
	static int	img_counter;
	static int	duration;

	if (img_counter == 4)
	{
		img_counter = 0;
		duration = 0;
	}
	duration++;
	if (duration == 55)
	{
		++img_counter;
		duration = 0;
	}
	if (img_counter == 0)
		ft_coll_position(root, "xpmfiles_bonus/bitcoin.xpm");
	else if (img_counter == 1)
		ft_coll_position(root, "xpmfiles_bonus/pixil-frame-0 (4).xpm");
	else if (img_counter == 2)
		ft_coll_position(root, "xpmfiles_bonus/pixil-frame-0 (5).xpm");
	else if (img_counter == 3)
		ft_coll_position(root, "xpmfiles_bonus/pixil-frame-0 (6).xpm");
	return (0);
}

int	ft_make_animation_components(t_root	*root)
{
	int	r;
	int	c;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == 'C')
				ft_render_next_coll(root);
			else if (root->map.data[r][c] == 'D')
				ft_render_next_enemy(root);
			c++;
		}
		r++;
	}
	return (0);
}
