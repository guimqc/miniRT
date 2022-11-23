/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:02:01 by gvial             #+#    #+#             */
/*   Updated: 2022/11/11 19:02:03 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_miniRT *minirt, int x, int y, int color)
{
	char	*dst;

	dst = minirt->display.addr + (y * minirt->display.line_length + x * \
		(minirt->display.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_miniRT *miniRT, int _x, int _y, double d, int rgb[3])
{
	int		x;
	int		y;
	double	r;

	r = d / 2;
	x = -1;
	y = -1;
	while (++y < miniRT->display.height)
	{
		while (++x < miniRT->display.width)
			if (pow(y - _y, 2) + pow(x - _x, 2) < pow(r, 2))
				my_mlx_pixel_put(miniRT, x, y, create_trgb(1, rgb[0], rgb[1], rgb[2]));
		x = -1;
	}
}

void	draw_test_scene(t_miniRT *miniRT)
{
	int	rgb[3] = {100, 175, 3};
	int	rgb2[3] = {0, 56, 230};

	draw_circle(miniRT, 400, -3400, 7000, rgb); // top
	draw_circle(miniRT, 400, 4200, 7000, rgb); // bottom
	draw_circle(miniRT, 4200, 400, 7000, rgb2); // right
	draw_circle(miniRT, 400, 400, 100, rgb2); // circle
}

void		create_window(t_miniRT *miniRT)
{
	miniRT->display.mlx = mlx_init();
	miniRT->display.mlx_win = mlx_new_window(miniRT->display.mlx,\
		miniRT->display.width, miniRT->display.height, "miniRT");
	miniRT->display.img = mlx_new_image(miniRT->display.mlx, \
	miniRT->display.width, miniRT->display.height);
	miniRT->display.addr = mlx_get_data_addr(miniRT->display.img, \
		&miniRT->display.bits_per_pixel, &miniRT->display.line_length, \
		&miniRT->display.endian);
	draw_test_scene(miniRT);
	mlx_put_image_to_window(miniRT->display.mlx, miniRT->display.mlx_win, \
		miniRT->display.img, 0, 0);
}
