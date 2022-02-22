/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:44:14 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 19:38:30 by mverger          ###   ########.fr       */
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

void	free_and_close(t_global *global)
{
	free(global->map);
	mlx_destroy_window(global->mlx, global->win);
	exit(0);
}
