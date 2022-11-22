/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:58:49 by gvial             #+#    #+#             */
/*   Updated: 2022/11/17 16:00:29 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init(t_miniRT *miniRT)
{
	miniRT->display.width = 800;
	miniRT->display.height = 600;
}
