/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:45:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/01/17 12:31:00 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	main(int ac, char **av)
{
	t_root	root;
	int		fd;
	char	*file;

	if (ac == 2 && av[1])
	{
		ft_check_map_ext(av[1], &root);
		fd = open(av[1], O_RDONLY);
		if (fd != 3)
			return (0);
		file = ft_read_file (fd);
		if (!file)
			return (0);
		ft_read_map (file, &root);
		ft_init (&root);
		close (fd);
		free (file);
	}
	else
		printf("\033[1;5;92m%s", "INVALID NUMBER OF ARGUMENTS\n");
	return (0);
}
