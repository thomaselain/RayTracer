/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:01:01 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/18 18:01:12 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <thread.h>

void				*thread_run_core(void *param)
{
	t_tcore		*tcore;

	tcore = (t_tcore*)param;
	tcore->alive = 3;
	tcore->max = WHSIZE;
	while (tcore->cur >= 0 && tcore->cur < tcore->max && tcore->alive >= 2)
	{
		img_set_pixel(tcore->img, tcore->cur % WIDTH, tcore->cur / WIDTH,
			ray_pixel(tcore->env, tcore->cur % WIDTH, tcore->cur / WIDTH));
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

	tcore = (t_tcore**)malloc(size * sizeof(t_tcore*));
	if (tcore == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if ((tcore[i] = (t_tcore*)malloc(sizeof(t_tcore))) != 0)
		{
			(tcore[i])->alive = 1;
			(tcore[i])->cur = i;
			(tcore[i])->step = size;
			(tcore[i])->img = img;
			(tcore[i])->env = env;
			if ((pthread_create(&((tcore[i])->thread), NULL,
				thread_run_core, (void*)(tcore[i]))) == 0)
				(tcore[i])->alive = 2;
		}
		else
			tcore[i] = 0;
		i++;
	}
	return (tcore);
}

float				thread_status(t_tcore **tcore, int size)
{
	double	stat;
	int		i;

	i = 0;
	stat = 0.0f;
	while (i < size)
	{
		if ((tcore[i])->alive < 2)
		{
			return (-1.0);
		}
		stat += (double)tcore[i]->cur / (double)size;
		i++;
	}
	return ((float)(stat / (double)(WHSIZE)));
}
