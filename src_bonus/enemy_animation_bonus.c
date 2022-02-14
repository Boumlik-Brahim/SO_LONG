/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:15:05 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 10:53:27 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_enemie_position(t_root	*root, char	*path)
{
	static int	r;
	static int	c;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == 'D')
				ft_draw_map(root, path, c, r);
			c++;
		}
		r++;
	}
}

int	ft_render_next_enemy(t_root *root)
{
	static int	img_counter;
	static int	duration;

	if (img_counter == 3)
	{
		img_counter = 0;
		duration = 0;
	}
	duration++;
	if (duration == 75)
	{
		++img_counter;
		duration = 0;
	}
	if (img_counter == 0)
		ft_enemie_position(root, "xpmfiles_bonus/demon.xpm");
	else if (img_counter == 1)
		ft_enemie_position(root, "xpmfiles_bonus/pixil-frame-0 (1).xpm");
	else if (img_counter == 2)
		ft_enemie_position(root, "xpmfiles_bonus/pixil-frame-0 (3).xpm");
	return (0);
}
