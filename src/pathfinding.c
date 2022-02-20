/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:08:41 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 19:37:54 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_into_map(t_global *global, char to_find)
{
	int	*pos_tofind;
	int	i;
	int	j;

	pos_tofind = (int *)malloc(sizeof(int) * 2);
					pos_tofind[0] = 1;
				pos_tofind[1] = 1;
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
				return (pos_tofind);
				//break;
			}
			j++;
		}
		i++;
	}
						//pos_tofind[0] = i;
				//pos_tofind[1] = j;
	return (pos_tofind);
}

int 	pathfinding(t_global *global, int direction) //free tab
{
	int	*pos_tofind;
	int	i;
	int	j;
	
	pos_tofind = find_into_map(global, 'P');
	i = pos_tofind[0];
	j = pos_tofind[1];
	if (direction == UP_DIRECTION)
	{
		if (global->map[i - 1][j] == '1')
			return (0);
		else
		{
			global->map[i][j] = '0';
			global->map[i - 1][j] = 'P';
			return (1);
		}
	}
	else if (direction == DOWN_DIRECTION)
	{
		if (global->map[i + 1][j] == '1')
			return (0);
		else
		{
			global->map[i][j] = '0';
			global->map[i + 1][j] = 'P';
			return (1);
		}
	}
	else if (direction == LEFT_DIRECTION)
	{
		if (global->map[i][j - 1] == '1')
			return (0);
		else
		{
			global->map[i][j] = '0';
			global->map[i][j - 1] = 'P';
			return (1);
		}
	}
	else if (direction == RIGHT_DIRECTION)
	{
		if (global->map[i][j + 1] == '1')
			return (0);
		else
		{
			global->map[i][j] = '0';
			global->map[i][j + 1] = 'P';
			return (1);
		}
	}
}