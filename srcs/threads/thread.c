/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:01:01 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/25 21:44:31 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <thread.h>
#include <color.h>

void				*thread_run_core(void *param)
{
	t_tcore		*tcore;

	tcore = (t_tcore*)param;
	tcore->alive = 3;
	tcore->max = WHSIZE;
	while (tcore->cur >= 0 && tcore->cur < tcore->max && tcore->alive >= 2)
	{
		img_set_pixel(tcore->img, tcore->cur % WIDTH, tcore->cur / WIDTH,
			add_filter(ray_pixel(tcore->env, tcore->cur % WIDTH,
				tcore->cur / WIDTH), tcore->env->camera.filter));
		tcore->cur += tcore->step;
	}
	pthread_exit(NULL);
	return (0);
}

void				thread_end(t_tcore **tcore, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		(tcore[i])->alive = 0;
		pthread_join(tcore[i]->thread, NULL);
		free(tcore[i]);
		i++;
	}
	free(tcore);
}

t_tcore				**thread_init(t_scene *env, t_img *img, const int size)
{
	t_tcore		**tcore;
	int			i;
	int			n;

	n = 1;
	if ((tcore = (t_tcore**)malloc(size * sizeof(t_tcore*))) == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if ((tcore[i] = (t_tcore*)malloc(sizeof(t_tcore))) != 0)
		{
			n = (n + 1) % 2;
			(tcore[i])->alive = 1;
			(tcore[i])->cur = (n == 1) ? i : (WHSIZE / size) * size + i - size;
			(tcore[i])->step = (n == 1) ? size : -size;
			(tcore[i])->img = img;
			(tcore[i])->env = env;
			if ((pthread_create(&((tcore[i])->thread), NULL,
				thread_run_core, (void*)(tcore[i]))) == 0)
				(tcore[i])->alive = 2;
		}
		i++;
	}
	return (tcore);
}

float				thread_status(t_tcore **tcore, int size)
{
	double	stat;
	double	cur;
	int		i;

	i = 0;
	stat = 0.0f;
	while (i < size)
	{
		if ((tcore[i])->alive < 2)
		{
			return (-1.0);
		}
		cur = (double)tcore[i]->cur;
		if (tcore[i]->step < 0)
			cur = WHSIZE - cur;
		stat += cur / (double)size;
		i++;
	}
	return ((float)(stat / (double)(WHSIZE)));
}
