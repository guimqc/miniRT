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

	dst = minirt->display.addr + (y * minirt->display.line_length + x * (minirt->display.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		create_window(t_miniRT *miniRT)
{
	miniRT->display.mlx = mlx_init();
	miniRT->display.mlx_win = mlx_new_window(miniRT->display.mlx, 500, 500, "miniRT");
	miniRT->display.img = mlx_new_image(miniRT->display.mlx, 1920, 1080);
	miniRT->display.addr = mlx_get_data_addr(miniRT->display.img, &miniRT->display.bits_per_pixel, &miniRT->display.line_length,
								&miniRT->display.endian);
	my_mlx_pixel_put(miniRT, 50, 50, create_trgb(1, 255, 0, 0));
	my_mlx_pixel_put(miniRT, 50, 51, create_trgb(1, 255, 0, 0));
	my_mlx_pixel_put(miniRT, 51, 50, create_trgb(1, 255, 0, 0));
	my_mlx_pixel_put(miniRT, 51, 51, create_trgb(1, 255, 0, 0));
	mlx_put_image_to_window(miniRT->display.mlx, miniRT->display.mlx_win, miniRT->display.img, 0, 0);
}
