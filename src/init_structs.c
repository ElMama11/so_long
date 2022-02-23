/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:34:57 by mverger           #+#    #+#             */
/*   Updated: 2022/02/23 17:18:48 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_pt2(t_global *global)
{
	global->img_list.exit.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/exit", &global->img_list.exit.img_width,
			&global->img_list.exit.img_height);
	global->img_list.ground.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/ground", &global->img_list.ground.img_width,
			&global->img_list.ground.img_height);
	global->img_list.wall.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/wall", &global->img_list.wall.img_width,
			&global->img_list.wall.img_height);
	global->img_list.wallb.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/wallB", &global->img_list.wallb.img_width,
			&global->img_list.wallb.img_height);
	global->img_list.walll.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/wallL", &global->img_list.walll.img_width,
			&global->img_list.walll.img_height);
	global->img_list.wallr.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/wallR", &global->img_list.wallr.img_width,
			&global->img_list.wallr.img_height);
	global->img_list.wallt.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/wallT", &global->img_list.wallt.img_width,
			&global->img_list.wallt.img_height);
}

void	init_img(t_global *global)
{
	global->img_list.character_front.img = mlx_xpm_file_to_image(global->mlx,
			"assets/character/front",
			&global->img_list.character_front.img_width,
			&global->img_list.character_front.img_height);
	global->img_list.chest.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/chest", &global->img_list.chest.img_width,
			&global->img_list.chest.img_height);
	global->img_list.cornerlb.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/cornerLB", &global->img_list.cornerlb.img_width,
			&global->img_list.cornerlb.img_height);
	global->img_list.cornerlt.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/cornerLT", &global->img_list.cornerlt.img_width,
			&global->img_list.cornerlt.img_height);
	global->img_list.cornerrb.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/cornerRB", &global->img_list.cornerrb.img_width,
			&global->img_list.cornerrb.img_height);
	global->img_list.cornerrt.img = mlx_xpm_file_to_image(global->mlx,
			"assets/textures/cornerRT", &global->img_list.cornerrt.img_width,
			&global->img_list.cornerrt.img_height);
	init_img_pt2(global);
}

void	init_window(t_global *global)
{
	global->win_width = ft_strlen(global->map[0]) * 50;
	global->win_height = ft_tablen(global->map) * 50;
	global->win = mlx_new_window(global->mlx, global->win_width,
			global->win_height, "so_long");
}

void	init_global(t_global *global, char **av)
{
	global->mlx = mlx_init();
	global->map = get_map(av);
	init_window(global);
	global->x = 0;
	global->y = 0;
	global->character_x = 0;
	global->character_y = 0;
	global->total_chest = 0;
	global->chest_picked = 0;
	global->move_count = 0;
	count_chest(global);
	init_img(global);
}
