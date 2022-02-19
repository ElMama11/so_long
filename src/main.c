/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:54 by mverger           #+#    #+#             */
/*   Updated: 2022/02/19 20:40:54 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_global(t_global *global, char **av)
{
	global->mlx = mlx_init();
	global->img = NULL;
	global->win = mlx_new_window(global->mlx, 1920, 1080, "so_long");
	global->x = 0;
	global->y = 0;
	global->map = get_map(av);
}

void	display_wall(t_global *global, int i, int j)
{
	int	img_width;
	int	img_height;

	if (i == 0 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == 0 && j > 0 && j < ft_strlen(global->map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == 0 && j == ft_strlen(global->map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallL", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j > 0 && j < ft_strlen(global->map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wall", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i > 0 && i < ft_tablen(global->map) - 1  && j == ft_strlen(global->map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallR", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(global->map) - 1 && j == 0)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLB", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(global->map) - 1 && j > 0 && j < ft_strlen(global->map[i]) - 2)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallB", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (i == ft_tablen(global->map) - 1 && j == ft_strlen(global->map[i]) - 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRB", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	display_ground(t_global *global)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_chest(t_global *global)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/chest", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_exit(t_global *global)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/exit", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_character(t_global *global)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/character/front", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_assets(char **av, t_global *global) //free map
{
	int		i;
	int		j;
		int k = 0;

	i = 0;
	init_global(global, av);
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == '1')
				display_wall(global,  i, j);
			else if (global->map[i][j] == '0')
				display_ground(global);
			else if (global->map[i][j] == 'C')
				display_chest(global);
			else if (global->map[i][j] == 'E')
				display_exit(global);
			else if (global->map[i][j] == 'P')
				display_character(global);
			j++;
		}
		global->y = global->y + 50;
		global->x = 0;
		i++;
	}
	ft_free_tab(global->map);
}

int	main(int ac, char **av) //read change la map
{
	t_global global;
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