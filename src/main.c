/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:54 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 19:32:38 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_global(t_global *global, char **av)
{
	global->mlx = mlx_init();
	global->img = NULL;
	global->win = mlx_new_window(global->mlx, 1920, 1080, "so_long");
	global->x = 0;
	global->y = 0;
	global->character_x = 0;
	global->character_y = 0;
	global->map = get_map(av);
}

void	key_press(t_global *global)
{
	mlx_key_hook(global->win, move_character, global);
	
}

int	main(int ac, char **av) //read change la map
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
	//key_press(&global);

	int	*pos_tofind;
	pos_tofind = find_into_map(&global, 'P');
	printf("%d et %d", pos_tofind[0], pos_tofind[1]);
	
	//mlx_loop(global.mlx);
}