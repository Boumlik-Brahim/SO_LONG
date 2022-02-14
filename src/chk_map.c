/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:43:41 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 12:30:25 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_check_map_ext(char	*av, t_root	*root)
{
	char	*ext;
	int		i;

	i = 0;
	while (av[i] != '\0')
		i++;
	ext = ft_strnstr(&av[1], ".ber", i);
	if (ext == NULL)
		ft_map_errors(root, "INVALID FILE EXTENTION\n");
	if (ft_strncmp(ext, ".ber", 5) != 0)
		ft_map_errors(root, "INVALID MAP FILE EXTENTION\n");
}

void	ft_checkwalls(t_root *root)
{
	int	c;
	int	r;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (root->map.data[0][c] != '1' || root->map.data[r][0] != '1'
					|| root->map.data[root->map.rows - 1][c] != '1'
					|| root->map.data[r][root->map.cols - 1] != '1' )
				ft_map_errors(root, "MAP NOT CLOSED,PLEASE CHECK MAP!!\n");
			else if (root->map.cols != (int)ft_strlen(root->map.data[r]))
				ft_map_errors(root, " YOUR MAP IS NOT RECTANGULAR\n");
			c++;
		}
		r++;
	}
}

void	ft_checkvalid(t_root *root)
{
	int	c;
	int	r;

	r = 0;
	while (r < root->map.rows)
	{
		c = 0;
		while (c < root->map.cols)
		{
			if (!(root->map.data[r][c] == '1' || root->map.data[r][c] == '0'
					|| root->map.data[r][c] == 'E'
					|| root->map.data[r][c] == 'C'
					|| root->map.data[r][c] == 'P'))
				ft_map_errors(root, "MAP DOESN'T RESPECT RULES OF MAP!!\n");
			c++;
		}
		r++;
	}
}

void	ft_checkchar(t_root *root)
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
				root->map.collectible++;
			else if (root->map.data[r][c] == 'E')
				root->map.exit++;
			else if (root->map.data[r][c] == 'P')
				root->map.player++;
			c++;
		}
		r++;
	}
	if (root->map.collectible < 1 || root->map.exit < 1
		|| root->map.player != 1)
		ft_map_errors(root, "INVALID MAP ELEMENTS PLEASE CHECK YOUR MAP!!\n");
}
