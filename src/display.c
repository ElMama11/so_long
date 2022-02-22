/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:56:32 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 20:05:32 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_chest(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.chest.img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_exit(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.exit.img, global->x, global->y);
	global->x = global->x + 50;
}

void	display_character(t_global *global)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.ground.img, global->x, global->y);
	mlx_put_image_to_window(global->mlx, global->win,
		global->img_list.character_front.img, global->x, global->y);
	global->character_x = global->x;
	global->character_y = global->y;
	global->x = global->x + 50;
}

void	display_wall(t_global *global, int i, int j)
{
	if (i == 0 && j == 0)
		put_corner(global, 1);
	else if (i == 0 && j > 0 && j < ft_strlen(global->map[i]) - 1)
		put_wall(global, 1);
	else if (i == 0 && j == ft_strlen(global->map[i]) - 1)
		put_corner(global, 2);
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j == 0)
		put_wall(global, 2);
	else if (i > 0 && i < ft_tablen(global->map) - 1 && j > 0
		&& j < ft_strlen(global->map[i]) - 1)
		put_wall(global, 3);
	else if (i > 0 && i < ft_tablen(global->map) - 1
		&& j == ft_strlen(global->map[i]) - 1)
		put_wall(global, 4);
	else if (i == ft_tablen(global->map) - 1 && j == 0)
		put_corner(global, 3);
	else if (i == ft_tablen(global->map) - 1 && j > 0
		&& j < ft_strlen(global->map[i]) - 1)
		put_wallb(global);
	else if (i == ft_tablen(global->map) - 1
		&& j == ft_strlen(global->map[i]) - 1)
		put_corner(global, 4);
}

void	display_assets(char **av, t_global *global)
{
	int		i;
	int		j;

	i = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == '1')
				display_wall(global, i, j);
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
}
