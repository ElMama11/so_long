/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:54 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 14:40:19 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_global(t_global *global, char **av)
{
	global->mlx = mlx_init();
	global->img = NULL;
	global->win = mlx_new_window(global->mlx, 1920, 1080, "so_long");
	global->x = 0;
	global->y = 0;
	global->character_x = 0;
	global->character_y = 0;
	global->total_chest = 0;
	global->chest_picked = 0;
	global->move_count = 0;
	global->map = get_map(av);
	count_chest(global);
}

void	key_press(t_global *global)
{	
	mlx_key_hook(global->win, move_character, global);
}

int	main(int ac, char **av) //read change la map, free global.map
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
	key_press(&global);
	mlx_loop(global.mlx);
}