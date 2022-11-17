/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:49:50 by gvial             #+#    #+#             */
/*   Updated: 2022/11/17 16:49:40 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "lib/libft/libft.h"
# include <mlx.h>

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
}	t_cylinder;

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
	int		fov;
	double	coordinate[3];
	double	orientation[3];
}	t_camera;

typedef struct Display
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}	t_display;

<<<<<<< HEAD

typedef struct MiniRT
=======
typedef struct s_minirt
>>>>>>> parsing
{
	t_display	display;
	t_light		light;
	t_camera	camera;
	t_ambient	ambient;
	t_cylinder	*cylinder;
	t_sphere	*sphere;
	t_plane		*plane;
}			t_miniRT;

//parse_mapfile.c
int	valid_name(char *str);
int	parse_mapfile(char *str);

// init
void	init(t_miniRT *miniRT);

// display
void	create_window(t_miniRT *miniRT);

// hook
void	hook(t_miniRT *miniRT);

#endif
