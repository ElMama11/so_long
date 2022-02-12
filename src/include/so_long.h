/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:49 by mverger           #+#    #+#             */
/*   Updated: 2022/02/12 18:47:53 by mverger          ###   ########.fr       */
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
}				t_global;

/* parsing.c */
int		check_wall(char **map);
char	**get_map(char **av);
int		check_map(char **av);
int		check_item_exit_start(char **map);
int		check_map_shape(char **map);
#endif