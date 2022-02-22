/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:28:48 by mverger           #+#    #+#             */
/*   Updated: 2022/02/22 19:22:19 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pathfinding_top(t_global *global)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = find_into_map(global, 'P');
	i = pos_tofind[0];
	j = pos_tofind[1];
	if (global->map[i - 1][j] == '1' || (global->map[i - 1][j] == 'E'
	&& global->chest_picked != global->total_chest))
		return (0);
	else
	{
		if (global->map[i - 1][j] == 'C')
			global->chest_picked = global->chest_picked + 1;
		if (pathfinding_exitt(global, i, j) == 1)
			return (2);
		global->map[i][j] = '0';
		global->map[i - 1][j] = 'P';
		return (1);
	}
	free(pos_tofind);
}

int	pathfinding_down(t_global *global)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = find_into_map(global, 'P');
	i = pos_tofind[0];
	j = pos_tofind[1];
	if (global->map[i + 1][j] == '1' || (global->map[i + 1][j] == 'E'
	&& global->chest_picked != global->total_chest))
		return (0);
	else
	{
		if (global->map[i + 1][j] == 'C')
			global->chest_picked = global->chest_picked + 1;
		if (pathfinding_exitd(global, i, j) == 1)
			return (2);
		global->map[i][j] = '0';
		global->map[i + 1][j] = 'P';
		return (1);
	}
	free(pos_tofind);
}

int	pathfinding_left(t_global *global)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = find_into_map(global, 'P');
	i = pos_tofind[0];
	j = pos_tofind[1];
	if (global->map[i][j - 1] == '1' || (global->map[i][j - 1] == 'E'
	&& global->chest_picked != global->total_chest))
		return (0);
	else
	{
		if (global->map[i][j - 1] == 'C')
			global->chest_picked = global->chest_picked + 1;
		if (pathfinding_exitl(global, i, j) == 1)
			return (2);
		global->map[i][j] = '0';
		global->map[i][j - 1] = 'P';
		return (1);
	}
	free(pos_tofind);
}

int	pathfinding_right(t_global *global)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = find_into_map(global, 'P');
	i = pos_tofind[0];
	j = pos_tofind[1];
	if (global->map[i][j + 1] == '1' || (global->map[i][j + 1] == 'E'
	&& global->chest_picked != global->total_chest))
		return (0);
	else
	{
		if (global->map[i][j + 1] == 'C')
			global->chest_picked = global->chest_picked + 1;
		if (pathfinding_exitr(global, i, j) == 1)
			return (2);
		global->map[i][j] = '0';
		global->map[i][j + 1] = 'P';
		return (1);
	}
	free(pos_tofind);
}
