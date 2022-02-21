/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:49 by mverger           #+#    #+#             */
/*   Updated: 2022/02/21 20:05:10 by mverger          ###   ########.fr       */
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
	int		character_x;
	int		character_y;
	int		total_chest;
	int		chest_picked;
	char	**map;
}				t_global;

/* ENUM */

enum {
	W_PRESS = 13,
	D_PRESS = 2,
	S_PRESS = 1,
	A_PRESS = 0,
	ESC_PRESS = 53,
};

/* main */
void	init_global(t_global *global, char **av);

/* general_utils.c */
void	count_chest(t_global *global);

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
void	put_corner(t_global *global, int corner, int img_width, int img_height);
void	put_wall(t_global *global, int wall, int img_width, int img_height);
void	put_wallB(t_global *global, int img_width, int img_height);

/* action.c */
int		move_character(int keycode, t_global *global);
void	move_up(t_global *global, int img_width, int img_height);
void	move_right(t_global *global, int img_width, int img_height);
void	move_down(t_global *global, int img_width, int img_height);
void	move_left(t_global *global, int img_width, int img_height);

/* pathfinding.c */
int		*find_into_map(t_global *global, char to_find);
int 	pathfinding(t_global *global, int direction);

/* pathfinding_utils.c */
int	pathfinding_top(t_global *global);
int	pathfinding_down(t_global *global);
int	pathfinding_left(t_global *global);
int	pathfinding_right(t_global *global);

/* pathfinding_exit.c */
int	pathfinding_exitt(t_global *global, int i, int j);
int	pathfinding_exitr (t_global *global, int i, int j);
int	pathfinding_exitd(t_global *global, int i, int j);
int	pathfinding_exitl(t_global *global, int i, int j);
#endif