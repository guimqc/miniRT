/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:49:50 by gvial             #+#    #+#             */
/*   Updated: 2022/05/25 16:49:55 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "lib/libft/libft.h"
# include <mlx.h>
# include <stdio.h>

typedef struct Plane
{
	int		color_rgb[3];
	double	coordinate[3];
	double	orientation[3];
}	t_plane;

typedef struct Sphere
{
	int		color_rgb[3];
	double	coordinate[3];
	double	diameter;
}	t_sphere;

typedef struct Cylinder
{
	int		color_rgb[3];
	double	coordinate[3];
	double	orientation[3];
	double	diameter;
	double	height;
}	t_Cylinder;

typedef struct Ambient
{
	int		color_rgb[3];
	double	ratio;
}	t_ambient;

typedef struct Light
{
	double	coordinate[3];
	double	brightness;
}	t_light;

typedef struct Camera
{
	int		FOV;
	double	coordinate[3];
	double	orientation[3];
}	t_camera;



typedef struct Display
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}	t_display;

typedef struct MiniRT
{
	t_display	display;
	t_light		light;
	t_camera	camera;
	t_ambient	ambient;
}	t_miniRT;

// init
void	init(t_miniRT *miniRT);

// display
void	create_window(t_miniRT *miniRT);

// hook
void	hook(t_miniRT *miniRT);

#endif
