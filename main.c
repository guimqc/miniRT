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

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	(void)	argc;
	(void)	argv;
	t_miniRT	miniRT;

	create_window(&miniRT);
	mlx_key_hook(miniRT.display.mlx_win, key_hook, &miniRT);
	mlx_hook(miniRT.display.mlx_win, 17, 0, close_x, &miniRT);
	mlx_loop(miniRT.display.mlx);
}
