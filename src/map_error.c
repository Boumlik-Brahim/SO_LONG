/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:44:07 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/10 21:11:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_rowlenght(t_root *root)
{
	int	row;

	row = 0;
	while (root->map.data[row])
		row++;
	return (row);
}

void	ft_map_errors(t_root *root, char *s)
{
	printf("\033[0;31m\e[1mError:");
	printf("\033[0;31m\e[1m%s", s);
	ft_free_map (root);
	exit (0);
}
