/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:44:14 by mverger           #+#    #+#             */
/*   Updated: 2022/02/21 18:54:26 by mverger          ###   ########.fr       */
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