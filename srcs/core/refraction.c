/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:16:16 by cchicote          #+#    #+#             */
/*   Updated: 2017/04/18 12:16:22 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>

void			get_refract2(t_object *h, float *n1, float *n2, t_vector4f *n)
{
	*n1 = h->refraction;
	*n2 = 1.0;
	*n = MUL(*n, -1);
}

void			get_refract3(t_object *h, float *n1, float *n2, float *angle)
{
	*n1 = 1.0;
	*n2 = h->refraction;
	*angle *= -1;
}

t_object		*get_refract(t_scene *s, t_object *h, t_ray *r)
{
	t_vector4f	n;
	float		n1;
	float		n2;
	float		angle;
	float		c2;

	if (h->refraction > 1.0)
	{
		r->state++;
		n = get_normal(h, *r);
		if ((angle = vector_dot(r->dir, n)) > 0)
			get_refract2(h, &n1, &n2, &n);
		else
			get_refract3(h, &n1, &n2, &angle);
		c2 = sqrt(1 - powf(n1 / n2, 2) * (1 - powf(angle, 2)));
		r->pos = (c2 < 0 ? ADD(r->pos, MUL(n, 0.00001)) : r->pos);
		if (c2 < 0)
			return (get_reflect(s, h, r));
		r->pos = SUB(r->pos, MUL(n, 0.00001));
		r->dir = ADD(MUL(r->dir, (n1 / n2)), MUL(n, ((n1 / n2) * angle - c2)));
	}
	else
		r->pos = ADD(r->pos, MUL(r->dir, 0.001));
	return (get_intersection(s->objects, r));
}
