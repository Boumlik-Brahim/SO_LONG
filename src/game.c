/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:49:19 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/16 22:00:36 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_close_game(t_root *root)
{
	mlx_destroy_window(root->mlx, root->mlx_win);
	exit (0);
	return (0);
}

int	ft_exit_game(t_root *root, char *msg, char color)
{
	if (color == 'r')
		printf("\033[0;31m\e[1m%s\n", msg);
	else
		printf("\033[0;32m\e[1m%s\n", msg);
	mlx_destroy_window(root->mlx, root->mlx_win);
	ft_free_map (root);
	exit (0);
}
