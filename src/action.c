/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:51:12 by mverger           #+#    #+#             */
/*   Updated: 2022/02/26 14:30:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->character_x, global->character_y);
	global->character_y = global->character_y - 50;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.character_front.img,
		global->character_x, global->character_y);
	global->move_count++;
	ft_printf("%d\n", global->move_count);
}

void	move_right(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->character_x, global->character_y);
	global->character_x = global->character_x + 50;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.character_front.img,
		global->character_x, global->character_y);
	global->move_count++;
	ft_printf("%d\n", global->move_count);
}

void	move_down(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->character_x, global->character_y);
	global->character_y = global->character_y + 50;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.character_front.img,
		global->character_x, global->character_y);
	global->move_count++;
	ft_printf("%d\n", global->move_count);
}

void	move_left(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->character_x, global->character_y);
	global->character_x = global->character_x - 50;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.character_front.img,
		global->character_x, global->character_y);
	global->move_count++;
	ft_printf("%d\n", global->move_count);
}

int	move_character(int keycode, t_global *global)
{
	if (keycode == W_PRESS && pathfinding(global, W_PRESS) == 1)
		move_up(global);
	else if (keycode == D_PRESS && pathfinding(global, D_PRESS) == 1)
		move_right(global);
	else if (keycode == S_PRESS && pathfinding(global, S_PRESS) == 1)
		move_down(global);
	else if (keycode == A_PRESS && pathfinding(global, A_PRESS) == 1)
		move_left(global);
	else if (keycode == ESC_PRESS)
		free_and_close(global);
	return (0);
}
