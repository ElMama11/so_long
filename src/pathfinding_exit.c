/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:55:07 by mverger           #+#    #+#             */
/*   Updated: 2022/02/21 20:04:40 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pathfinding_exitt(t_global *global, int i, int j)
{
	if (global->map[i - 1][j] == 'E' && global->chest_picked == global->total_chest)
		return (1);
	else
		return (0);
}

int	pathfinding_exitd(t_global *global, int i, int j)
{
	if (global->map[i + 1][j] == 'E' && global->chest_picked == global->total_chest)
		return (1);
	else
		return (0);
}

int	pathfinding_exitl(t_global *global, int i, int j)
{
	if (global->map[i][j - 1] == 'E' && global->chest_picked == global->total_chest)
		return (1);
	else
		return (0);
}

int	pathfinding_exitr(t_global *global, int i, int j)
{
	if (global->map[i][j + 1] == 'E' && global->chest_picked == global->total_chest)
		return (1);
	else
		return (0);
}