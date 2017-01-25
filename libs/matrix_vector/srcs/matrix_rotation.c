/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 12:52:20 by svassal           #+#    #+#             */
/*   Updated: 2016/10/16 15:37:41 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** Make a matrix rotation using three float numbers
*/

t_matrix4f		*matrix_rotation_flo(float f[3])
{
	t_matrix4f	m_x;
	t_matrix4f	m_y;
	t_matrix4f	m_z;
	t_matrix4f	*r_m;

	init_matrix_id(&m_x);
	init_matrix_id(&m_y);
	init_matrix_id(&m_z);
	r_m = 0;
	matrix_set_elem(&m_x, 1, 1, cosf(X));
	matrix_set_elem(&m_x, 1, 2, -sinf(X));
	matrix_set_elem(&m_x, 2, 1, sinf(X));
	matrix_set_elem(&m_x, 2, 2, cosf(X));
	matrix_set_elem(&m_y, 0, 0, cosf(Y));
	matrix_set_elem(&m_y, 0, 2, -sinf(Y));
	matrix_set_elem(&m_y, 2, 0, sinf(Y));
	matrix_set_elem(&m_y, 2, 2, cosf(Y));
	matrix_set_elem(&m_z, 0, 0, cosf(Z));
	matrix_set_elem(&m_z, 0, 1, -sinf(Z));
	matrix_set_elem(&m_z, 1, 0, sinf(Z));
	matrix_set_elem(&m_z, 1, 1, cosf(Z));
	write_over_matrix(r_m, matrix_mul(&m_y, &m_x));
	write_over_matrix(r_m, matrix_mul(&m_z, r_m));
	return (r_m);

}

/*
** Make a matrix rotation using three float numbers and an angle in float
*/

t_matrix4f		*matrix_rotation_flo_angle(float f[3], float angle)
{
	float			cs[2];
	t_matrix4f		*r_m;

	cs[0] = (float)cos(angle);
	cs[1] = (float)sin(angle);
	r_m = make_matrix();
	r_m->data[0][0] = cs[0] + X * X * (1 - cs[0]);
	r_m->data[0][1] = X * Y * (1 - cs[0]) - Z * cs[1];
	r_m->data[0][2] = X * Z * (1 - cs[0]) + Y * cs[1];
	r_m->data[1][0] = Y * X * (1 - cs[0]) + Z * cs[1];
	r_m->data[1][1] = cs[0] + Y * Y * (1 - cs[0]);
	r_m->data[1][2] = Y * Z * (1 - cs[0]) - X * cs[1];
	r_m->data[2][0] = Z * X * (1 - cs[0]) - Y * cs[1];
	r_m->data[2][1] = Z * Y * (1 - cs[0]) + X * cs[1];
	r_m->data[2][2] = cs[0] + Z * Z * (1 - cs[0]);
	return (r_m);
}

/*
** Make a matrix rotation using two vectors
*/

t_matrix4f		*matrix_rotation_vec_two(t_vector4f *forward, t_vector4f *up)
{
	t_vector4f		*f;
	t_vector4f		*r;
	t_vector4f		*u;
	t_matrix4f		*r_m;

	f = vector_normalize(forward);
	r = vector_normalize(up);
	write_over_vector(r, vector_cross(f, r));
	u = vector_cross(f, r);
	r_m = matrix_rotation_vec_three(f, u, r);
	delete_vector(r);
	delete_vector(u);
	delete_vector(r);
	return (r_m);
}

/*
** Make a matrix rotation using three vectors
*/

t_matrix4f		*matrix_rotation_vec_three(t_vector4f *forward,
	t_vector4f *up, t_vector4f *right)
{
	t_matrix4f		*r_m;

	r_m = make_matrix();
	matrix_set_elem(r_m, 0, 0, vector_get_x(right));
	matrix_set_elem(r_m, 0, 1, vector_get_y(right));
	matrix_set_elem(r_m, 0, 2, vector_get_z(right));
	matrix_set_elem(r_m, 1, 0, vector_get_x(up));
	matrix_set_elem(r_m, 1, 1, vector_get_y(up));
	matrix_set_elem(r_m, 1, 2, vector_get_z(up));
	matrix_set_elem(r_m, 2, 0, vector_get_x(forward));
	matrix_set_elem(r_m, 2, 1, vector_get_y(forward));
	matrix_set_elem(r_m, 2, 2, vector_get_z(forward));
	return (r_m);
}
