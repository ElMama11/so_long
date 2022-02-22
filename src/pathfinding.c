/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:08:41 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 20:10:20 by mverger          ###   ########.fr       */
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
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos_tofind);
}

int	pathfinding_pt2(t_global *global, int direction)
{
	if (direction == A_PRESS)
	{
		if (pathfinding_left(global) == 1)
			return (1);
		else if (pathfinding_left(global) == 2)
			free_and_close(global);
	}
	else if (direction == D_PRESS)
	{
		if (pathfinding_right(global) == 1)
			return (1);
		else if (pathfinding_right(global) == 2)
			free_and_close(global);
	}
	return (0);
}

int	pathfinding(t_global *global, int direction)
{
	if (direction == W_PRESS)
	{
		if (pathfinding_top(global) == 1)
			return (1);
		else if (pathfinding_top(global) == 2)
			free_and_close(global);
	}
	else if (direction == S_PRESS)
	{
		if (pathfinding_down(global) == 1)
			return (1);
		else if (pathfinding_down(global) == 2)
			free_and_close(global);
	}
	else if (pathfinding_pt2(global, direction) == 1)
		return (1);
	return (0);
}
