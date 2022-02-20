/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:56:32 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 16:36:35 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	global->character_x = global->x;
	global->character_y = global->y;
	global->x = global->x + 50;
}

void	display_wall(t_global *global, int i, int j)
{
	int	img_width;
	int	img_height;

	if (i == 0 && j == 0)
		put_corner(global, 1, img_width, img_height);
	else if (i == 0 && j > 0 && j < ft_strlen(global->map[i]) - 1)
		put_wall(global, 1, img_width, img_height);
	else if (i == 0 && j == ft_strlen(global->map[i]) - 1)
		put_corner(global, 2, img_width, img_height);
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j == 0)
		put_wall(global, 2, img_width, img_height);
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j > 0 && j < ft_strlen(global->map[i]) - 1)
		put_wall(global, 3, img_width, img_height);
	else if (i > 0 && i < ft_tablen(global->map) - 1  && j == ft_strlen(global->map[i]) - 1)
		put_wall(global, 4, img_width, img_height);
	else if (i == ft_tablen(global->map) - 1 && j == 0)
		put_corner(global, 3, img_width, img_height);
	else if (i == ft_tablen(global->map) - 1 && j > 0 && j < ft_strlen(global->map[i]) - 1)
		put_wallB(global, img_width, img_height);
	else if (i == ft_tablen(global->map) - 1 && j == ft_strlen(global->map[i]) - 1)
		put_corner(global, 4, img_width, img_height);
}

void	display_assets(char **av, t_global *global)
{
	int		i;
	int		j;

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