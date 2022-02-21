/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:51:12 by mverger           #+#    #+#             */
/*   Updated: 2022/02/21 19:50:01 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_global *global, int img_width, int img_height)
{
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
	global->character_y = global->character_y - 50;
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/character/front", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
}

void	move_right(t_global *global, int img_width, int img_height)
{
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
	global->character_x = global->character_x + 50;
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/character/front", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
}

void	move_down(t_global *global, int img_width, int img_height)
{
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
	global->character_y = global->character_y + 50;
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/character/front", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
}

void	move_left(t_global *global, int img_width, int img_height)
{
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/textures/ground", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
	global->character_x = global->character_x - 50;
	global->img = mlx_xpm_file_to_image(global->mlx, "assets/character/front", &img_width, &img_height);
	mlx_put_image_to_window(global->mlx, global->win, global->img, global->character_x, global->character_y);
}

int	move_character(int keycode, t_global *global)
{
	int img_width;
	int	img_height;
	int	*pos_tofind;
	
	if (keycode == W_PRESS && pathfinding(global, W_PRESS) == 1)
		move_up(global, img_width, img_width);
		//si pathfinding return 2, je close
	else if (keycode == D_PRESS && pathfinding(global, D_PRESS) == 1)
		move_right(global, img_width, img_width);
	else if (keycode == S_PRESS && pathfinding(global, S_PRESS) == 1)
		move_down(global, img_width, img_width);
	else if (keycode == A_PRESS && pathfinding(global, A_PRESS) == 1)
		move_left(global, img_width, img_width);
	return (0);
}