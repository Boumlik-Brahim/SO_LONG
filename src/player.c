/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:49:34 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/16 22:01:51 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_player_position(t_root *root)
{
	int	r;
	int	c;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[r][c] == 'P')
			{
				root->player.x = c;
				root->player.y = r;
			}
			c++;
		}
		r++;
	}
}
