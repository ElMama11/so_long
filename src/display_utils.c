/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:39 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 15:05:45 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_ground(t_global *global)
{
	int	img_width;
	int	img_height;

	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}

void	put_corner(t_global *global, int corner, int img_width, int img_height)
{
	if (corner == 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 2)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 3)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerLB", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 4)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/cornerRB", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	put_wall(t_global *global, int wall, int img_width, int img_height)
{
	if (wall == 1)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallT", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 2)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallL", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 3)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wall", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 4)
	{
		global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallR", &img_width, &img_height);
		mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	put_wallB(t_global *global, int img_width, int img_height)
{
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/wallB", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->x, global->y);
	global->x = global->x + 50;
}