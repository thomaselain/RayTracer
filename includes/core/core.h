/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:28:23 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/27 16:11:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include <vector.h>
# include <libft.h>
# define WIDTH	800
# define HEIGHT	600
# define WHSIZE	(WIDTH * HEIGHT)

/*
** Contains every objects types
*/

typedef enum		e_type
{
	UNKNOWN, SPOT, PLANE, SPHERE, CONE, CYLINDER
}					t_type;

/*
** Contains every informations usefull about the camera
*/

typedef struct		s_camera
{
	t_vector4f		origin;
	t_vector4f		direction;
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
*/

typedef struct		s_scene
{
	t_camera		camera;
	unsigned int	background;
	t_list			*objects;
	t_list			*lights;
}					t_scene;

/*
** Return the argb color at pixel x,y
*/

unsigned int		ray_pixel(t_scene *scene, int x, int y);

#endif
