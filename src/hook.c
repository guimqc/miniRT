/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:46:01 by gvial             #+#    #+#             */
/*   Updated: 2022/05/26 11:46:03 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	close_x(t_miniRT *miniRT)
{
	mlx_destroy_window(miniRT->display.mlx, miniRT->display.mlx_win);
	exit(0);
}

static int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		return (printf("13\n"));
	if (keycode == 1)
		return (printf("1\n"));
	if (keycode == 0)
		return (printf("0\n"));
	if (keycode == 2)
		return (printf("2\n"));
	return (0);
}

void	hook(t_miniRT *miniRT)
{
	mlx_key_hook(miniRT->display.mlx_win, key_hook, miniRT);
	mlx_hook(miniRT->display.mlx_win, 17, 0, close_x, miniRT);
	mlx_loop(miniRT->display.mlx);
}
