/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:34:44 by svassal           #+#    #+#             */
/*   Updated: 2016/10/16 14:02:07 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Return vector's x value
*/

float		vector_get_x(t_vector4f *v)
{
	return (v->x);
}

/*
** Return vector's y value
*/

float		vector_get_y(t_vector4f *v)
{
	return (v->y);
}

/*
** Return vector's z value
*/

float		vector_get_z(t_vector4f *v)
{
	return (v->z);
}

/*
** Return vector's w value
*/

float		vector_get_w(t_vector4f *v)
{
	return (v->w);
}
