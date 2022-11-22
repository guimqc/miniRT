/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:49:50 by gvial             #+#    #+#             */
/*   Updated: 2022/11/22 15:14:11 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "lib/libft/libft.h"
# include <mlx.h>

typedef struct s_obj
{
	int		color_rgb[3];
	double	coordinate[3];
	double	orientation[3];
	double	diameter;
	double	height;
}	t_obj;

typedef struct s_ambient
{
	int		color_rgb[3];
	double	ratio;
}	t_ambient;

typedef struct s_light
{
	double	coordinate[3];
	double	brightness;
}	t_light;

typedef struct s_camera
{
	int		fov;
	double	coordinate[3];
	double	orientation[3];
}	t_camera;

typedef struct s_display
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

typedef struct s_minirt
{
	t_display	display;
	t_light		light;
	t_camera	camera;
	t_ambient	ambient;
	t_obj		*obj;
}			t_miniRT;

//parse_mapfile.c
int		valid_name(char *str);
int		elem_names(char **elems);
char	**parse_contents(char *file1);
char	**parse_mapfile(char *str);

//parse_utils.c
char	**error_message(char *str, char *strfree);
int		check_file_size(int fd, char *file);
void	free2d(char **split);

// init
void	init(t_miniRT *miniRT);

// display
void	create_window(t_miniRT *miniRT);

// hook
void	hook(t_miniRT *miniRT);

#endif
