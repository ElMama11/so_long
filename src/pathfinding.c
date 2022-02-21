/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:08:41 by mverger           #+#    #+#             */
/*   Updated: 2022/02/21 20:30:15 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_into_map(t_global *global, char to_find)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = (int *)ft_memallocexit(sizeof(int) * 2);
	i = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == 'P')
			{
				pos_tofind[0] = i;
				pos_tofind[1] = j;
				break;
			}
			j++;
		}
		i++;
	}
	return (pos_tofind);
}

int	pathfinding(t_global *global, int direction)
{
	if (direction == W_PRESS)
	{
		if (pathfinding_top(global) == 1)
			return (1);
		//else if (pathfinding_top(global) == 2)
		//close
	}
	else if (direction == S_PRESS)
	{
		if (pathfinding_down(global) == 1)
			return (1);
	//	else if (pathfinding_top(global) == 2)
		//close
	}
	else if (direction == A_PRESS)
	{
		if (pathfinding_left(global) == 1)
			return (1);
		//else if (pathfinding_top(global) == 2)
		//close
	}
	else if (direction == D_PRESS)
	{
		if (pathfinding_right(global) == 1)
			return (1);
		//else if (pathfinding_top(global) == 2)
		//close
	}
	return (0);
}