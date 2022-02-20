/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:29:23 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 14:36:14 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	check_wall(char **map)
{
	int	i;
	int	j;
	int	nb_line_map;
	int	lenght_line;

	i = 0;
	nb_line_map = ft_tablen(map) - 1;
	lenght_line = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == nb_line_map) && map[i][j] != '1')
				return (1);
			if ((i != 0 || i != nb_line_map) && (j == 0 || j == lenght_line) && map[i][j] != '1')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**get_map(char **av)
{
	int		map_fd;
	char	buffer[1000];
	char 	**map;
	
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
		return (NULL);
	read(map_fd, buffer, 1000);
	map = ft_split(buffer, '\n');
	map[ft_tablen(map) - 1][ft_strlen(map[0])] = '\0';
	close(map_fd);
	return (map);
}

int	check_item_exit_start(char **map)
{
	int	nb_line_map;
	int	i;
	int	j;
	int	item_exit_start[3];
	
	i = 1;
	nb_line_map = ft_tablen(map) - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				item_exit_start[0] = 1;
			if (map[i][j] == 'E')
				item_exit_start[1] = 1;
			if (map[i][j] == 'P')
				item_exit_start[2] = 1;
			
			j++;
		}
		i++;
	}
	if (item_exit_start[0] == 1 && item_exit_start[1] == 1 && item_exit_start[2] == 1)
		return (0);
	else
		return (1);
}

int	check_map_shape(char **map)
{
	int	nb_line_map;
	int	i;
	
	i = 1;
	nb_line_map = ft_tablen(map);
	if (nb_line_map < 3)
		return (1);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **av)
{
	char	**map;
	int		i; 

	i = 0;
	map = get_map(av);
	if (check_wall(map) == 1)
		return (1);
	if (check_item_exit_start(map) == 1)
		return (1);
	if (check_map_shape(map) == 1)
		return (1);
	ft_free_tab(map);
	return (0);
}