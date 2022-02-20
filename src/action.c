/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:51:12 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 19:32:28 by mverger          ###   ########.fr       */
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
	if (keycode == W_PRESS)
		move_up(global, img_width, img_width);
	else if (keycode == D_PRESS)
		move_right(global, img_width, img_width);
	else if (keycode == S_PRESS)
		move_down(global, img_width, img_width);
	else if (keycode == A_PRESS)
		move_left(global, img_width, img_width);
	return (0);
}