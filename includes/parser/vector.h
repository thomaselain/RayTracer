/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:15:09 by svassal           #+#    #+#             */
/*   Updated: 2016/10/16 14:01:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <math.h>
# include <core.h>
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

t_vector4f		*vector_mul_vec(t_vector4f *v1, t_vector4f *v2);

/*
** Multiply vector's datas by a float value
*/

t_vector4f		*vector_mul_flo(t_vector4f *v, float r);

/*
** Add first vector and the second one
*/

t_vector4f		*vector_add_vec(t_vector4f *v1, t_vector4f *v2);

/*
** Add vector's datas and a float value
*/

t_vector4f		*vector_add_flo(t_vector4f *v, float r);

/*
** Divide first vector by the second one
*/

t_vector4f		*vector_div_vec(t_vector4f *v1, t_vector4f *v2);

/*
** Divide vector's datas by a float value
*/

t_vector4f		*vector_div_flo(t_vector4f *v, float r);

/*
** Substract first vector by the second one
*/

t_vector4f		*vector_sub_vec(t_vector4f *v1, t_vector4f *v2);

/*
** Substract vector's datas by a float value
*/

t_vector4f		*vector_sub_flo(t_vector4f *v, float r);

/*
** Check if two vectors are equal (1) or not (0)
*/

short			vector_equals(t_vector4f *v1, t_vector4f *v2);

/*
** Gives the absolute of a vector
*/

t_vector4f		*vector_abs(t_vector4f *v);

/*
** Return the higher value between each of the vector's data
*/

float			vector_max(t_vector4f *v);

/*
** Return vector's length
*/

float			vector_length(t_vector4f *v);

/*
** Gives the dot product of two vectors v1 and v2
*/

float			vector_dot(t_vector4f *v1, t_vector4f *v2);

/*
** Gives the cross product of vector 1 and vector 2
*/

t_vector4f		*vector_cross(t_vector4f *v1, t_vector4f *v2);

/*
** Return the normal of the given vector
*/

t_vector4f		*vector_normalize(t_vector4f *v);

/*
** Rotate the vector v and return it as a fresh new copy
*/

t_vector4f		*vector_rotate(t_vector4f *v, t_vector4f *axis, float angle);

/*
** Linear interpolation
*/

t_vector4f		*vector_lerp(t_vector4f *v, t_vector4f *dest, float lerp_fact);

#endif
