/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:34 by telain            #+#    #+#             */
/*   Updated: 2017/01/27 19:26:13 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

void				get_camera_plane(t_scene *scene)
{ 
	scene->camera.screen_h = 1.2 * tan((scene->camera.fov * M_PI / 180.0) / 2.0);
	scene->camera.screen_w = (float)WIDTH / (float)HEIGHT * scene->camera.screen_h;
	scene->xindent = scene->camera.screen_w / (float)WIDTH;
	scene->yindent = scene->camera.screen_h / (float)HEIGHT;
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
	m_up = MUL(scene->camera.up, -scene->camera.screen_h / 2);
	m_right = MUL(scene->camera.right, -scene->camera.screen_w / 2);
	ret = ADD(scene->camera.origin, m_dir);
	ret = ADD(ADD(ret, m_right), m_up);
	ret = ADD(ret, MUL(scene->camera.up, scene->yindent * y));
	ret = ADD(ret, MUL(scene->camera.right, scene->xindent * x));
	return (ret);
}

unsigned int		ray_pixel(t_scene *scene, int x, int y)
{
	t_ray		ray;
	t_object	*hit;
	int		c;

	c = 0;
	ray.dir = vector_normalize(SUB(get_ray(scene, x, y), scene->camera.origin));
	ray.pos = scene->camera.origin;
	hit = get_intersection(scene, &ray);
	c = adjust_color(scene, hit, ray);
	return (c);
}
