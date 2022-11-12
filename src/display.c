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

void		create_window(t_miniRT *miniRT)
{
	miniRT->display.mlx = mlx_init();
	miniRT->display.mlx_win = mlx_new_window(miniRT->display.mlx, 500, 500, "miniRT");
}
