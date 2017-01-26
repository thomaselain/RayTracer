/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:34 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 21:29:32 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

void				get_camera_plane(t_scene *scene)
{ 
	scene->xindent = (float)WIDTH / (float)HEIGHT;
	scene->yindent = (float)HEIGHT / (float)WIDTH;
	scene->camera.up = (t_vector4f){0.0f, 0.0f, 1.0f, 0.0f};
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
	m_up = DIV(scene->camera.up, -2.0f);
	m_right = DIV(scene->camera.right, -2.0f);
	ret = ADD(scene->camera.origin, m_dir);
	ret = ADD(ADD(ret, m_right), m_up);
	ret = ADD(ret, MUL(scene->camera.up, scene->yindent * y));
	ret = ADD(ret, MUL(scene->camera.right, scene->xindent * x));
	return (ret);
}

unsigned int		ray_pixel(t_scene *scene, int x, int y)
{
	t_ray	ray;

	ray.dir = vector_normalize(SUB(get_ray(scene, x, y), scene->camera.origin));
	ray.pos = scene->camera.origin;
//	printf("%f\n%f\n%f\n\n", ray.dir.x, ray.dir.y, ray.dir.z);
	return (adjust_color(get_intersection(scene, &ray)));
}
