/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:54 by mverger           #+#    #+#             */
/*   Updated: 2022/02/19 17:43:55 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_global(t_global *global, char **av)
{
	global->mlx = mlx_init();
	global->img = NULL;
	global->win = mlx_new_window(global->mlx, 1024, 720, "so_long");
	global->x = 0;
	global->y = 0;
	global->map = get_map(av);
}

void	display_wall(t_global *global, char **map, int i, int j)
{
	int	img_width;
	int	img_height;

	if (i == 0 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLT.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == 0 && j > 0 && j < ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallT.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == 0 && j == ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRT.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(map) - 1 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallL.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(map) - 1 && j > 0 && j < ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wall.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(map) - 1  && j == ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallR.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(map) - 1 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLB.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(map) - 1 && j > 0 && j < ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallB.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(map) - 1 && j == ft_strlen(map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRB.xpm", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	display_ground(t_global *global, char **map, int i, int j)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_assets(char **av, t_global *global) //free map
{
	char	**map;
	int		i;
	int		j;
		int k = 0;

	
	i = 0;
	map = get_map(av);
	// printf("%d\n", ft_tablen(map));
	// while (map[k])
	// {
	// 	printf("%s\n", map[k]);
	// 	k++;
	// }
	init_global(global, av);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				display_wall(global, map, i, j);
			else if (map[i][j] == '0')
				display_ground(global, map, i, j);
			j++;
		}
		global->y = global->y + 50;
		global->x = 0;
		i++;
	}
	ft_free_tab(map);
}

int	main(int ac, char **av)
{
	t_global global;
	init_global(&global, av);
	if (ac != 2)
	{
		write(2, "Error\nMap is missing\n", 22);
		return (0);
	}
	if (check_map(av) == 1)
	{
		write(2, "Error\nBad map format\n", 22);
		return (0);
	}
	display_assets(av, &global);
	// int k = 0;
	// printf("%d\n", ft_tablen(global.map));
	// 	while (global.map[k])
	// {
	// 	printf("%s\n", global.map[k]);
	// 	k++;
	// }
	// printf("%d\n", ft_tablen(global.map));
	// while (global.map[k])
	// {
	// 	printf("%s\n", global.map[k]);
	// 	k++;
	// }
	// 	printf("%d\n", ft_tablen(global.map));
	mlx_loop(global.mlx);
}