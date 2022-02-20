/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:52:22 by mverger           #+#    #+#             */
/*   Updated: 2022/02/20 16:06:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int	closee(int keycode, t_vars *vars)
{	
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars, void *img)
{
	printf("%d\n", keycode);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 20, 20);
	return (0);
}

int	mouse_pos_hook(int keycode, t_vars *vars)
{
	int x, y = 0;
	
	mlx_mouse_get_pos(vars->win, &x, &y);
	printf("%d\n%d\n", x, y);
	return (0);
}

int	main(void)
{
	t_vars vars;
	//char	*relative_path = "assets/textures/re.xpm";
	int		img_width;
	int		img_height;
	int		i, j = 64;
	
	vars.img = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "hello");
		
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse_pos_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, closee, &vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 20, 20);
	mlx_loop(vars.mlx);
}