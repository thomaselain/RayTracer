/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:19:22 by svassal           #+#    #+#             */
/*   Updated: 2016/10/16 11:54:51 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Fill vector's datas, using values contained int f table
*/

void			define_vector(t_vector4f *v, float f[4])
{
	v->x = X;
	v->y = Y;
	v->z = Z;
	v->w = W;
}

/*
** Return an allocated vector, initialized at 0;
*/

t_vector4f		*make_vector(void)
{
	t_vector4f		*r;
	float			f[4];

	if ((r = malloc(sizeof(t_vector4f))) == 0)
		return (0);
	X = 0;
	Y = 0;
	Z = 0;
	W = 0;
	define_vector(r, f);
	return (r);
}

/*
** Fill vector's values with 0, free the memory allocated to it,
** and put his pointer to 0
*/

void			delete_vector(t_vector4f *v)
{
	float		f[4];

	X = 0;
	Y = 0;
	Z = 0;
	W = 0;
	if (v != 0)
	{
		define_vector(v, f);
		free(v);
	}
	v = 0;
}

/*
** Free the content of vector dest, and save the content
** the vector src in it instead
*/

void			write_over_vector(t_vector4f *dest, t_vector4f *src)
{
	if (src != 0)
	{
		delete_vector(dest);
		dest = src;
	}
	src = 0;
}
