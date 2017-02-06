/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:28:23 by aljourda          #+#    #+#             */
/*   Updated: 2017/02/06 21:36:26 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include <vector.h>
# include <libft.h>
#include <stdio.h>
# define WIDTH	1000
# define HEIGHT	800
# define WHSIZE	(WIDTH * HEIGHT)

/*
** Contains every objects types
*/

typedef enum		e_type
{
	UNKNOWN, DIRECTIONAL, SPOT, PLANE, SPHERE, CONE, CYLINDER, CIRCLE, SQUARE
}					t_type;

/*
**	Contains every informations usefull about the current ray
*/

typedef struct		s_ray
{
	t_vector4f		pos;
	t_vector4f		dir;
}					t_ray;

/*
** Contains every informations usefull about the camera
*/

typedef struct		s_camera
{
	float			screen_w;
	float			screen_h;
	t_vector4f		origin;
	t_vector4f		direction;
	t_vector4f		right;
	t_vector4f		up;
	char			fov;
}					t_camera;

/*
** Contains each information parsed from the JSON file
*/

typedef struct		s_object
{
	t_type			type;
	t_vector4f		origin;
	t_vector4f		direction;
	int				color;
	float			diffuse;
	float			reflection;
	union
	{
		float		intensity;
		float		radius;
		float		angle;
	};
	char			*comment;
}					t_object;

/*
** Contains the scene structure
** xindent and yindent are the distance between each pixel in space
*/

typedef struct		s_scene
{
	float			xindent;
	float			yindent;
	t_camera		camera;
	unsigned int	background;
	t_list			*objects;
	t_list			*lights;
}					t_scene;

/*
** Return the argb color at pixel (x,y)
*/

unsigned int		ray_pixel(t_scene *scene, int x, int y);

#endif
