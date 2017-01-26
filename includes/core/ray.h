/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:56:12 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 19:30:19 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define A						(val[0])
# define B						(val[1])
# define C						(val[2])
# define D						(val[3])
# define X1						(val[5])
# define X2						(val[6])
# define RET					(val[4])
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

int						adjust_color(t_object *hit);

/*
**	Calculates the intersection with objects
*/

t_object				*get_intersection(t_scene *s, t_ray *ray);

/*
**	Calculates the intersections for each different object
*/

float					find_sphere_inter(t_scene *s, t_ray *ray, t_object *obj);

#endif
