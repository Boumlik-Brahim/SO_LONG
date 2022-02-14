/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:44:55 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 10:56:25 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_move_right(t_root *root)
{
	int	x;
	int	y;

	x = root->player.x;
	y = root->player.y;
	if (root->map.data[y][x + 1] == 'C')
		root->map.collectible--;
	if (root->map.data[y][x + 1] == '1'
		|| (root->map.data[y][x + 1] == 'E' && root->map.collectible != 0))
		return ;
	if (root->map.data[y][x + 1] == 'E')
		ft_exit_game(root, "YOU WIN CONGRATS", 'h');
	if (root->map.data[y][x + 1] == 'D')
		ft_exit_game(root, "HH YOU LOSE", 'r');
	root->map.data[y][x] = '0';
	root->map.data[y][x + 1] = 'P';
	ft_player_position (root);
	ft_make_components (root, x, y);
}

void	ft_move_left(t_root *root)
{
	int	x;
	int	y;

	x = root->player.x;
	y = root->player.y;
	if (root->map.data[y][x - 1] == 'C')
		root->map.collectible--;
	if (root->map.data[y][x - 1] == '1'
		|| (root->map.data[y][x - 1] == 'E' && root->map.collectible != 0))
		return ;
	if (root->map.data[y][x - 1] == 'E')
		ft_exit_game(root, "YOU WIN CONGRATS", 'h');
	if (root->map.data[y][x - 1] == 'D')
		ft_exit_game(root, "HH YOU LOSE", 'r');
	root->map.data[y][x] = '0';
	root->map.data[y][x - 1] = 'P';
	ft_player_position (root);
	ft_make_components (root, x, y);
}

void	ft_move_up(t_root *root)
{
	int	x;
	int	y;

	x = root->player.x;
	y = root->player.y;
	if (root->map.data[y - 1][x] == 'C')
		root->map.collectible--;
	if (root->map.data[y - 1][x] == '1'
		|| (root->map.data[y - 1][x] == 'E' && root->map.collectible != 0))
		return ;
	if (root->map.data[y - 1][x] == 'E')
		ft_exit_game(root, "YOU WIN CONGRATS", 'h');
	if (root->map.data[y - 1][x] == 'D')
		ft_exit_game(root, "HH YOU LOSE", 'r');
	root->map.data[y][x] = '0';
	root->map.data[y - 1][x] = 'P';
	ft_player_position (root);
	ft_make_components (root, x, y);
}

void	ft_move_down(t_root *root)
{
	int	x;
	int	y;

	x = root->player.x;
	y = root->player.y;
	if (root->map.data[y + 1][x] == 'C')
		root->map.collectible--;
	if (root->map.data[y + 1][x] == '1'
		|| (root->map.data[y + 1][x] == 'E' && root->map.collectible != 0))
		return ;
	if (root->map.data[y + 1][x] == 'E')
		ft_exit_game(root, "YOU WIN CONGRATS", 'h');
	if (root->map.data[y + 1][x] == 'D')
		ft_exit_game(root, "HH YOU LOSE", 'r');
	root->map.data[y][x] = '0';
	root->map.data[y + 1][x] = 'P';
	ft_player_position (root);
	ft_make_components (root, x, y);
}
