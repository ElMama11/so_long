/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:44:14 by mverger           #+#    #+#             */
/*   Updated: 2022/03/27 15:11:34 by mverger          ###   ########.fr       */
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

int	free_and_close(t_global *global)
{
	ft_free_tab(global->map);
	mlx_destroy_image(global->mlx, global->img_list.chest.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerlb.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerlt.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerrb.img);
	mlx_destroy_image(global->mlx, global->img_list.cornerrt.img);
	mlx_destroy_image(global->mlx, global->img_list.exit.img);
	mlx_destroy_image(global->mlx, global->img_list.ground.img);
	mlx_destroy_image(global->mlx, global->img_list.wall.img);
	mlx_destroy_image(global->mlx, global->img_list.wallb.img);
	mlx_destroy_image(global->mlx, global->img_list.walll.img);
	mlx_destroy_image(global->mlx, global->img_list.wallr.img);
	mlx_destroy_image(global->mlx, global->img_list.wallt.img);
	mlx_destroy_image(global->mlx, global->img_list.character_front.img);
	mlx_clear_window(global->mlx, global->win);
	mlx_destroy_window(global->mlx, global->win);
	exit(0);
}

void	check_open(int map_fd, char **av)
{
	if (map_fd == -1 || ft_strstr(av[1], ".ber") != 1)
	{
		write(2, "Error: bad path or entry format\n", 32);
		exit(EXIT_FAILURE);
	}
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str_malloc;

	str_malloc = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str_malloc = (char *)malloc((i + j + 1) * sizeof(char));
	if (str_malloc == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str_malloc[i] = s1[i];
	while (s2[j])
		str_malloc[i++] = s2[j++];
	str_malloc[i] = '\0';
	free(s1);
	return (str_malloc);
}
