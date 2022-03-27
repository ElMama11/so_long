/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:49 by mverger           #+#    #+#             */
/*   Updated: 2022/03/27 14:59:23 by mverger          ###   ########.fr       */
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

typedef struct s_img {
	void	*img;
	int		img_height;
	int		img_width;
}				t_img;

typedef struct s_img_list {
	t_img	chest;
	t_img	cornerlb;
	t_img	cornerlt;
	t_img	cornerrb;
	t_img	cornerrt;
	t_img	exit;
	t_img	ground;
	t_img	wall;
	t_img	wallb;
	t_img	walll;
	t_img	wallr;
	t_img	wallt;
	t_img	character_front;
}				t_img_list;

typedef struct s_global {
	void		*mlx;
	void		*win;
	t_img_list	img_list;
	int			x;
	int			y;
	int			character_x;
	int			character_y;
	int			total_chest;
	int			chest_picked;
	int			move_count;
	int			win_height;
	int			win_width;
	char		**map;
}				t_global;

/* ENUM */

enum {
	W_PRESS = 13,
	D_PRESS = 2,
	S_PRESS = 1,
	A_PRESS = 0,
	ESC_PRESS = 53,
};

/* init_structs.c */
void	init_global(t_global *global, char **av);
void	init_img(t_global *global);
void	init_img_pt2(t_global *global);
void	init_window(t_global *global);

/* general_utils.c */
void	count_chest(t_global *global);
int		free_and_close(t_global *global);
void	check_open(int map_fd, char **av);
char	*ft_strjoin_custom(char *s1, char *s2);

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
void	display_wall(t_global *global, size_t i, size_t j);
void	display_assets(t_global *global);

/* display_utils.c */
void	display_ground(t_global *global);
void	put_corner(t_global *global, int corner);
void	put_wall(t_global *global, int wall);
void	put_wallb(t_global *global);

/* action.c */
int		move_character(int keycode, t_global *global);
void	move_up(t_global *global);
void	move_right(t_global *global);
void	move_down(t_global *global);
void	move_left(t_global *global);

/* pathfinding.c */
int		*find_into_map(t_global *global, char to_find);
int		pathfinding(t_global *global, int direction);

/* pathfinding_utils.c */
int		pathfinding_top(t_global *global);
int		pathfinding_down(t_global *global);
int		pathfinding_left(t_global *global);
int		pathfinding_right(t_global *global);

/* pathfinding_exit.c */
int		pathfinding_exitt(t_global *global, int i, int j);
int		pathfinding_exitr(t_global *global, int i, int j);
int		pathfinding_exitd(t_global *global, int i, int j);
int		pathfinding_exitl(t_global *global, int i, int j);
#endif