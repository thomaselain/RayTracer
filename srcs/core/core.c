/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:34 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 16:30:42 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

void				get_camera_plane(t_scene *scene)
{
	scene->xindent = 1.0f / (float)WIDTH;
	scene->yindent = 1.0f / (float)HEIGHT;
	scene->camera.up = (t_vector4f){0.0f, 1.0f, 0.0f, 0.0f};
	scene->camera.right = vector_cross(scene->camera.up,
			scene->camera.direction);
	scene->camera.right = vector_normalize(scene->camera.right);
	scene->camera.up = vector_cross(scene->camera.direction,
			scene->camera.right);
	scene->camera.up = vector_normalize(scene->camera.up);
}

t_vector4f			get_ray(t_scene *scene, int x, int y)
{
	t_vector4f		m_up;
	t_vector4f		m_right;
	t_vector4f		m_dir;
	t_vector4f		ret;

	m_dir = MUL(scene->camera.direction, 0.6f);
	m_up = DIV(scene->camera.up, 2.0f);
	m_right = DIV(scene->camera.right, -2.0f);
	ret = ADD(ADD(ADD(SUB(ADD(m_dir, m_up), m_right), scene->camera.origin),
				MUL(scene->camera.up, scene->yindent * y)),
			MUL(scene->camera.right, scene->xindent * x));
	return (vector_normalize(ret));
}

unsigned int		ray_pixel(t_scene *scene, int x, int y)
{
	t_vector4f	ray;

	ray = vector_normalize(SUB(get_ray(scene, x, y), scene->camera->origin));
	return ();
}
