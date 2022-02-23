/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:44:14 by mverger           #+#    #+#             */
/*   Updated: 2022/02/23 16:57:11 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_chest(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == 'C')
				global->total_chest = global->total_chest + 1;
			j++;
		}
		i++;
	}
}

int	free_and_close(t_global *global)
{
	free(global->map);
	mlx_destroy_image(global->mlx, global->img_list.chest.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerlb.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerlt.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerrb.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerrt.img);
	mlx_destroy_image(global->mlx, global->img_list.exit.img);
	mlx_destroy_image(global->mlx, global->img_list.ground.img);
	mlx_destroy_image(global->mlx, global->img_list.wall.img);
	mlx_destroy_image(global->mlx, global->img_list.wallb.img);
	mlx_destroy_image(global->mlx, global->img_list.walll.img);
	mlx_destroy_image(global->mlx, global->img_list.wallr.img);
	mlx_destroy_image(global->mlx, global->img_list.wallt.img);
	mlx_destroy_image(global->mlx, global->img_list.character_front.img);
	mlx_clear_window(global->mlx, global->win);
	mlx_destroy_window(global->mlx, global->win);
	exit(0);
}
