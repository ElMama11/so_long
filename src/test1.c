/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:52:22 by mverger           #+#    #+#             */
/*   Updated: 2022/02/10 14:01:58 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int	i, j;

	i = 500;
	j = 400;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "hello");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 8, 0x00FF0000);
	
	my_mlx_pixel_put(&img, 7, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 4, 12, 0x00FF0000);

	my_mlx_pixel_put(&img, 3, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 2, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 1, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 0, 8, 0x00FF0000);
	
	my_mlx_pixel_put(&img, 1, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 2, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 3, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 4, 4, 0x00FF0000);

	my_mlx_pixel_put(&img, 50, 50 , 0x00FF0000);
	my_mlx_pixel_put(&img, 51, 50, 0x00FF0000);
	my_mlx_pixel_put(&img, 52, 50, 0x00FF0000);
	
	my_mlx_pixel_put(&img, 53, 51, 0x00FF0000);
	my_mlx_pixel_put(&img, 54, 52, 0x00FF0000);
	my_mlx_pixel_put(&img, 55, 53, 0x00FF0000);
	my_mlx_pixel_put(&img, 56, 54, 0x00FF0000);

	while (i <= 600 && j <= 500)
		my_mlx_pixel_put(&img, i++, j++, 0x00FF0000);
	while (i <= 700 && j >= 400)
		my_mlx_pixel_put(&img, i++, j--, 0x00FF0000);
	while (i >= 600 && j >= 300)
		my_mlx_pixel_put(&img, i--, j--, 0x00FF0000);
	while (i >= 500 && j <= 400)
		my_mlx_pixel_put(&img, i--, j++, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}