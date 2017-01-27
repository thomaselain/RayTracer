/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:56:12 by telain            #+#    #+#             */
/*   Updated: 2017/01/27 18:55:45 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H


# define CAMDIR					(s->camera->direction)
# define CAMPOS					(s->camera->origin)
# define COLOR_R(color)			(color & 0xff)
# define COLOR_G(color)			((color & 0xff00) >> 8)
# define COLOR_B(color)			((color & 0xff0000) >> 16)
# define ADD(v1, v2)			(vector_add_vec(v1, v2))
# define SUB(v1, v2)			(vector_sub_vec(v1, v2))
# define MUL(v1, f)				(vector_mul_flo(v1, f))
# define DIV(v1, f)				(vector_div_flo(v1, f))

/*
**	Modifies the up and right vectors in the camera structure
*/

void					get_camera_plane(t_scene *scene);

/*
**	Calculates the actual ray to draw
*/

t_vector4f				get_ray(t_scene *scene, int x, int y);

/*
**	Returns a new Color (Changed with the object param)
*/

int						adjust_color(t_scene *s, t_object *hit, t_ray ray);

/*
**	Calculates the intersection with all objects
*/

t_object				*get_intersection(t_scene *s, t_ray *ray);

/*
**	Calculates the intersections for each different object
*/

float					find_sphere_inter(t_scene *s, t_ray *ray, t_object *obj);

/*
**	Calls the good function, depending of the type of the hit object
*/

t_vector4f				get_normal(t_object *o, t_ray ray);

/*
**	Returns the normal vector for the given object
*/

t_vector4f				sphere_normal(t_object *o, t_ray ray);

unsigned int			find_shadow(t_scene *s, t_object *hit, t_ray ray);

#endif
