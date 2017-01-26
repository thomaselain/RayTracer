/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:56:12 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 16:30:34 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define R(color)		(color & 0xff)
# define G(color)		((color & 0xff00) >> 8)
# define B(color)		((color & 0xff0000) >> 16)
# define ADD(v1, v2)	(vector_add_vec(v1, v2))
# define SUB(v1, v2)	(vector_sub_vec(v1, v2))
# define MUL(v1, f)		(vector_mul_flo(v1, f))
# define DIV(v1, f)		(vector_div_flo(v1, f))


/*
**	Modifies the up and right vectors in the camera structure
*/

void					get_camera_plane(t_scene *scene);

/*
**	Calculates the actual ray to draw
*/

t_vector4f				get_ray(t_scene *scene, int x, int y);


/*
**	Calculates the intersection with objects
*/

t_object				*get_intersection(t_scene *s, t_ray *ray);

#endif
