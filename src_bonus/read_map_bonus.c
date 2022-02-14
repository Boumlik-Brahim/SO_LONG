/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:44:24 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 11:01:21 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_free_map(t_root *root)
{
	int	i;

	i = -1;
	if (root->mlx != NULL)
		root->mlx = NULL;
	if (root->mlx_win != NULL)
		root->mlx_win = NULL;
	if (root->map.data != NULL)
		while (++i < root->map.rows)
			free(root->map.data[i]);
	root->map.data = NULL;
}

char	*ft_read_file(int fd)
{
	char			*buf;
	static char		*res;
	int				n;

	buf = (char *)malloc(sizeof(char) + 2);
	if (!buf)
		return (NULL);
	if (res == NULL)
		res = ft_strdup("");
	n = 1;
	while (n != 0)
	{
		n = read(fd, buf, 1);
		if (n == -1)
		{
			free (buf);
			free (res);
			return (NULL);
		}
		buf[n] = '\0';
		res = ft_strjoin(res, buf);
	}
	free (buf);
	return (res);
}

char	**ft_return_map(char	*file, int	*i)
{
	int		j;
	char	**dst;

	j = 0;
	while (file[j])
	{
		if ((file[j] == '\n' && file[j + 1] == '\n')
			|| file[0] == '\n'
			|| (file[j] == '\n' && file[j + 1] == '\0'))
			*i = -1;
		j++;
	}
	dst = ft_split(file, '\n');
	if (!dst)
		return (NULL);
	return (dst);
}

void	ft_read_map(char	*file, t_root	*root)
{
	int	i;

	i = 0;
	root->map.data = ft_return_map(file, &i);
	if (root->map.data == NULL)
		return ;
	if (i == -1)
	{
		ft_map_errors(root, "INVALID MAP ELEMENTS PLEASE CHECK YOUR MAP!!\n");
		return ;
	}
}
