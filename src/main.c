/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:54 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 19:47:04 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_global	global;

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
	init_global(&global, av);
	display_assets(av, &global);
	mlx_key_hook(global.win, move_character, &global);
	mlx_loop(global.mlx);
}
