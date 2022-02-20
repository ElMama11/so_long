/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:49 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 14:03:07 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

# include "../../mlx/mlx.h"

# include "../../libft/libft.h"

/* STRUCTS */

typedef struct s_global {
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	char	**map;
}				t_global;

/* main */
void	init_global(t_global *global, char **av);

/* parsing.c */
int		check_wall(char **map);
char	**get_map(char **av);
int		check_map(char **av);
int		check_item_exit_start(char **map);
int		check_map_shape(char **map);

/* display.c */
void	display_chest(t_global *global);
void	display_exit(t_global *global);
void	display_character(t_global *global);
void	display_wall(t_global *global, int i, int j);
void	display_assets(char **av, t_global *global);

/* display_utils.c */
void	display_ground(t_global *global);

#endif