/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:08:32 by telain            #+#    #+#             */
/*   Updated: 2017/04/19 17:06:39 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <math.h>
# define X			f[0]
# define Y			f[1]
# define Z			f[2]
# define W			f[3]

typedef struct	s_vector4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector4f;

/*
** Return an allocated vector, initialized at 0;
*/

t_vector4f		*make_vector();

/*
**	returns the vector filled with the x, y and z values (w is 1 default)
*/

t_vector4f		new_vector(float x, float y, float z);

/*
** Fill vector's datas, using values contained int f table
*/

void			define_vector(t_vector4f *v, float f[4]);

/*
** Fill vector's values with 0, free the memory allocated to it,
** and put his pointer to 0
*/

void			delete_vector(t_vector4f *v);

/*
** Free the content of vector dest, and save the content
** the vector src in it instead
*/

void			write_over_vector(t_vector4f *dest, t_vector4f *src);

/*
** Return vector's x value
*/

float			vector_get_x(t_vector4f *v);

/*
** Return vector's y value
*/

float			vector_get_y(t_vector4f *v);

/*
** Return vector's z value
*/

float			vector_get_z(t_vector4f *v);

/*
** Return vector's w value
*/

float			vector_get_w(t_vector4f *v);

/*
** Multiply first vector by the second one
*/

t_vector4f		vector_mul_vec(t_vector4f v1, t_vector4f v2);

/*
** Multiply vector's datas by a float value
*/

t_vector4f		vector_mul_flo(t_vector4f v, float r);

/*
** Add first vector and the second one
*/

t_vector4f		vector_add_vec(t_vector4f v1, t_vector4f v2);

/*
** Add vector's datas and a float value
*/

t_vector4f		vector_add_flo(t_vector4f v, float r);

/*
** Divide first vector by the second one
*/

t_vector4f		vector_div_vec(t_vector4f v1, t_vector4f v2);

/*
** Divide vector's datas by a float value
*/

t_vector4f		vector_div_flo(t_vector4f v, float r);

/*
** Substract first vector by the second one
*/

t_vector4f		vector_sub_vec(t_vector4f v1, t_vector4f v2);

/*
** Substract vector's datas by a float value
*/

t_vector4f		vector_sub_flo(t_vector4f v, float r);

/*
** Check if two vectors are equal (1) or not (0)
*/

char			vector_equals(t_vector4f v1, t_vector4f v2);

/*
** Gives the absolute of a vector
*/

t_vector4f		vector_abs(t_vector4f v);

/*
** Return the higher value between each of the vector's data
*/

float			vector_max(t_vector4f v);

/*
** Return vector's length
*/

float			vector_length(t_vector4f v);

/*
** Gives the dot product of two vectors v1 and v2
*/

float			vector_dot(t_vector4f v1, t_vector4f v2);

/*
** Gives the cross product of vector 1 and vector 2
*/

t_vector4f		vector_cross(t_vector4f v1, t_vector4f v2);

/*
** Return the normal of the given vector
*/

t_vector4f		vector_normalize(t_vector4f v);

/*
** Rotate the vector v and return it as a fresh new copy
*/

t_vector4f		vector_rotate(t_vector4f v, t_vector4f axis, float angle);

/*
** Linear interpolation
*/

t_vector4f		vector_lerp(t_vector4f v, t_vector4f dest, float lerp_fact);

/*
**	Returns the distance between v1 and v2
*/

float			vector_dist(t_vector4f v1, t_vector4f v2);

/*
**	Returns the projection of the point "p" on the axis starting at "s",
**	belong the vector "axis"
*/

t_vector4f		vector_projection(t_vector4f s, t_vector4f axis, t_vector4f p);

#endif
