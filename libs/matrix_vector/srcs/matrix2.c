/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:38:45 by svassal           #+#    #+#             */
/*   Updated: 2017/01/25 18:55:39 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#define L	datas[0]
#define R	datas[1]
#define B	datas[2]
#define T	datas[3]
#define N	datas[4]
#define F	datas[5]

/*
** Init perspective with given parameters
*/

t_matrix4f		matrix_perspective(float fov, float aspect_ratio,
	float z_near, float z_far)
{
	t_matrix4f		r_m;
	float			tan_half_fov;
	float			z_range;

	init_matrix_id(&r_m);
	tan_half_fov = tanf(fov / 2);
	z_range = z_near - z_far;
	matrix_set_elem(&r_m, 0, 0, 1.0 / (tan_half_fov * aspect_ratio));
	matrix_set_elem(&r_m, 1, 1, 1.0 / tan_half_fov);
	matrix_set_elem(&r_m, 2, 2, (-z_near - z_far) / z_range);
	matrix_set_elem(&r_m, 2, 3, 2 * z_far * z_near / z_range);
	matrix_set_elem(&r_m, 3, 2, 1);
	matrix_set_elem(&r_m, 3, 3, 0);
	return (r_m);
}

/*
** Init ortographic projection with given parameters
*/

t_matrix4f		matrix_orthographic(float datas[6])
{
	t_matrix4f	r_m;
	float		width;
	float		height;
	float		depth;

	init_matrix_id(&r_m);
	width = R - L;
	height = T - B;
	depth = F - N;
	matrix_set_elem(&r_m, 0, 0, 2.0 / width);
	matrix_set_elem(&r_m, 0, 3, -(R + L) / width);
	matrix_set_elem(&r_m, 1, 1, 2.0 / height);
	matrix_set_elem(&r_m, 1, 3, -(T + B) / height);
	matrix_set_elem(&r_m, 2, 2, -2.0 / depth);
	matrix_set_elem(&r_m, 2, 3, -(F + N) / depth);
	return (r_m);
}
