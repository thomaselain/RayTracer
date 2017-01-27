/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:47:32 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/18 15:55:32 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include <pthread.h>
# include <img.h>
# include <core.h>

typedef struct		s_tcore
{
	pthread_t		thread;
	int				alive;
	int				cur;
	int				step;
	int				max;
	t_img			*img;
	t_scene			*env;
}					t_tcore;

t_tcore				**thread_init(t_scene *env, t_img *img, const int size);
void				*thread_run_core(void *param);
void				thread_end(t_tcore **tcore, int size);
float				thread_status(t_tcore **tcore, int size);

#endif
