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

int	close_x(t_miniRT *miniRT)
{
	mlx_destroy_window(miniRT->display.mlx, miniRT->display.mlx_win);
	exit(0);
}

int	key_hook(int keycode)
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
