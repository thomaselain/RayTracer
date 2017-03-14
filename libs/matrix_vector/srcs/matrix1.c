/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:19:21 by svassal           #+#    #+#             */
/*   Updated: 2017/03/13 20:52:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** Multiply two matrix
*/

t_matrix4f		matrix_mul(t_matrix4f m1, t_matrix4f m2)
{
	int			i;
	int			j;
	t_matrix4f	r_m;

	i = -1;
	init_matrix_id(&r_m);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			matrix_set_elem(&r_m, i, j, matrix_get_elem(m1, i , 0) *
				matrix_get_elem(m2, 0, j) + matrix_get_elem(m1, i , 1) *
					matrix_get_elem(m2, 1, j) + matrix_get_elem(m1, i , 2) *
						matrix_get_elem(m2, 2, j) + matrix_get_elem(m1, i , 3) *
							matrix_get_elem(m2, 3, j));
		}
	}
	return (r_m);
}

/*
** Scale matrix
*/

t_matrix4f		matrix_init_scale(float x, float y, float z)
{
	t_matrix4f		r_m;

	init_matrix_id(&r_m);
	matrix_set_elem(&r_m, 0, 0, x);
	matrix_set_elem(&r_m, 1, 1, y);
	matrix_set_elem(&r_m, 2, 2, z);
	return (r_m);
}

/*
** Convert a matrix to a vector
*/

t_vector4f		matrix_trans_to_vec(t_matrix4f m, t_vector4f v)
{
	t_vector4f		r_v;
	float			f[4];

	X = matrix_get_elem(m, 0, 0) * vector_get_x(&v) + matrix_get_elem(m, 0, 1) *
		vector_get_y(&v) +matrix_get_elem(m, 0, 2) * vector_get_z(&v) +
			matrix_get_elem(m, 0, 3) * vector_get_w(&v);
	Y = matrix_get_elem(m, 1, 0) * vector_get_x(&v) + matrix_get_elem(m, 1, 1) *
		vector_get_y(&v) +matrix_get_elem(m, 1, 2) * vector_get_z(&v) +
			matrix_get_elem(m, 1, 3) * vector_get_w(&v);
	Z = matrix_get_elem(m, 2, 0) * vector_get_x(&v) + matrix_get_elem(m, 2, 1) *
		vector_get_y(&v) +matrix_get_elem(m, 2, 2) * vector_get_z(&v) +
			matrix_get_elem(m, 2, 3) * vector_get_w(&v);
	W = matrix_get_elem(m, 3, 0) * vector_get_x(&v) + matrix_get_elem(m, 3, 1) *
		vector_get_y(&v) +matrix_get_elem(m, 3, 2) * vector_get_z(&v) +
			matrix_get_elem(m, 3, 3) * vector_get_w(&v);
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Init matrix screen space translation
*/

t_matrix4f		matrix_scrn_space_trans(float half_width, float half_height)
{
	t_matrix4f		r_m;

	init_matrix_id(&r_m);
	matrix_set_elem(&r_m, 0, 0, half_width);
	matrix_set_elem(&r_m, 1, 1, -half_height);
	matrix_set_elem(&r_m, 0, 3, half_width);
	matrix_set_elem(&r_m, 1, 3, half_height);
	return (r_m);
}

/*
** Init matrix translation
*/

t_matrix4f		matrix_translation(float x, float y, float z)
{
	t_matrix4f		r_m;

	init_matrix_id(&r_m);
	matrix_set_elem(&r_m, 0, 3, x);
	matrix_set_elem(&r_m, 1, 3, y);
	matrix_set_elem(&r_m, 2, 3, z);
	return (r_m);
}
