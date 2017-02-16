/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:56:12 by telain            #+#    #+#             */
/*   Updated: 2017/02/16 16:16:16 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define CAMDIR					(s->camera->direction)
# define CAMPOS					(s->camera->origin)
# define MAX_REFLECTION			(2)
# define MAX_SIZE				(100000.0)
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

float					find_sphere_inter(t_ray *ray, t_object *obj);
float					find_cone_inter(t_ray *ray, t_object *obj);
float					find_plane_inter(t_ray *ray, t_object *obj);
float					find_cylinder_inter(t_ray *ray, t_object *obj);
float					find_circle_inter(t_ray *ray, t_object *obj);
float					find_square_inter(t_ray *ray, t_object *obj);

/*
**	Calls the good function, depending of the type of the hit object
*/

t_vector4f				get_normal(t_object *o, t_ray ray);

/*
**	Returns the normal vector for the given object depending on its type
*/

t_vector4f				cone_normal(t_object *o, t_ray ray);
t_vector4f				sphere_normal(t_object *o, t_ray ray);
t_vector4f				cylinder_normal(t_object *o, t_ray ray);

/*
**	Ends an object
*/

float					find_cap(t_ray *r, t_object *o, float r1, float r2);

/*
**	Tells if the given object is in a shadow cone or not
*/

float					find_shadow(t_scene *s, t_object *hit, t_ray ray, t_ray light);

/*
**	Calculates the specular light for the given object
*/

float					specular_light(t_scene *s, t_object *hit, t_ray ray, t_vector4f light);

/*
**	Changes the ray coordinates to get the reflected object
*/

t_object*				get_reflect(t_scene *s, t_object *hit, t_ray *ray);

/*
*	TO_DELETE	returns a color, depending on the ray position to draw a grid on the plane
*/

unsigned int			find_grid_color(t_object *hit, t_ray ray);

/*
**	Returns the good light vector, depending on the type of the light
*/

t_vector4f				get_light_vector(t_object *light, t_ray ray);

/*
**	Modifies the normal at the intersection,
**	depending on the object's parameters
*/

t_vector4f				normal_modifications(t_object *o, t_vector4f n, t_ray ray);

/*
**	Calculates the noise for the given coordinates
*/

float					noise(t_object *o, t_vector4f pos);
float					perlin(float x, float y, float z);


#endif
