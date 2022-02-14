/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:43:55 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/18 16:11:11 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_key_hook(int keycode, t_root *root)
{
	if (keycode == 53)
		ft_exit_game(root, "Game Over", 'r');
	else if (keycode == 2)
		ft_move_right(root);
	else if (keycode == 0)
		ft_move_left(root);
	else if (keycode == 13)
		ft_move_up(root);
	else if (keycode == 1)
		ft_move_down(root);
	return (0);
}
