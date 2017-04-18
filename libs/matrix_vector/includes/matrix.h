/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:56:40 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 21:04:06 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define ANGLE		1
# define NO_ANGLE	2
# include "vector.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_matrix4f
{
	float		data[4][4];
}				t_matrix4f;

/*
** Init each element of the matrix according to a defined patern,
** thes ones with the same X and Y coordinate at 1, and the others to 0
*/

void			init_matrix_id(t_matrix4f *m);

/*
** Create a matrix, allocating enough memory for it
*/

t_matrix4f		*make_matrix(void);

/*
** Delete a matrix, freeing the memory alloacted for it
*/

void			delete_matrix(t_matrix4f *m);

/*
** Replace the existing "dest" matrix (freeing it) by the src one
*/

void			write_over_matrix(t_matrix4f *dest, t_matrix4f *src);

/*
** Set the element of the matrix to the value given as parameter
*/

void			matrix_set_elem(t_matrix4f *m, int x, int y, float value);

/*
** Return the element of the matrix at given element
*/

float			matrix_get_elem(t_matrix4f m, int x, int y);

/*
** Change the full array of the matrix to the one given as parameter
*/

void			matrix_set_array(t_matrix4f *m, float d[4][4]);

/*
** Make a matrix rotation using three float numbers
*/

t_matrix4f		matrix_rotation_flo(float f[3]);

/*
** Make a matrix rotation using three float numbers and an angle in float
*/

t_matrix4f		matrix_rotation_flo_angle(float f[3], float angle);

/*
** Make a matrix rotation using two vectors
*/

t_matrix4f		matrix_rotation_vec_two(t_vector4f forward, t_vector4f up);

/*
** Make a matrix rotation using three vectors
*/

t_matrix4f		matrix_rotation_vec_three(t_vector4f forward,
		t_vector4f up, t_vector4f right);

/*
** Multiply two matrix
*/

t_matrix4f		matrix_mul(t_matrix4f m1, t_matrix4f m2);

/*
** Scale matrix
*/

t_matrix4f		matrix_init_scale(float x, float y, float z);

/*
** Convert a matrix to a vector
*/

t_vector4f		matrix_trans_to_vec(t_matrix4f m, t_vector4f v);

/*
** Init matrix screen space translation
*/

t_matrix4f		matrix_scrn_space_trans(float half_width, float half_height);

/*
** Init matrix translation
*/

t_matrix4f		matrix_translation(float x, float y, float z);

/*
** Init perspective with given parameters
*/

t_matrix4f		matrix_perspective(float fov, float aspect_ratio,
		float z_near, float z_far);

/*
** Init ortographic projection with given parameters
*/

t_matrix4f		matrix_orthographic(float datas[6]);

#endif
