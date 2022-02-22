/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:39 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 19:42:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_ground(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->x, global->y);
	global->x = global->x + 50;
}

void	put_corner(t_global *global, int corner)
{
	if (corner == 1)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.cornerlt.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 2)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.cornerrt.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 3)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.cornerlb.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (corner == 4)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.cornerrb.img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	put_wall(t_global *global, int wall)
{
	if (wall == 1)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.wallt.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 2)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.walll.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 3)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.wall.img, global->x, global->y);
		global->x = global->x + 50;
	}
	else if (wall == 4)
	{
		mlx_put_image_to_window(global->mlx, global->win,
			global->img_list.wallr.img, global->x, global->y);
		global->x = global->x + 50;
	}
}

void	put_wallb(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.wallb.img, global->x, global->y);
	global->x = global->x + 50;
}
