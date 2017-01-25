/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:22:31 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:25:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <parse_major.h>
#define GET		0
#define INIT	1
#define CLEAN	2
#define SET		3

/*
** Write the second string over the first one
*/

static void		str_write_over(char **s1, char *s2)
{
	ft_strclr(*s1);
	*s1 = ft_strdup(s2);
	ft_strclr(s2);
}

/*
** Parse the file given as filedescriptor
*/

static void		parse(int fd)
{
	char	*json;
	char	*tmp;
	t_scene	*s;

	json = 0;
	tmp = 0;
	while (get_next_line(fd, &tmp) != 0)
	{
		str_write_over(&tmp, ft_strtrim(tmp));
		if (json == 0)
			json = ft_strdup(tmp);
		else
			str_write_over(&json, ft_strjoin(json, tmp));
	}
	close(fd);
	if (tmp != 0)
		ft_strclr(tmp);
	scene_string(SET, json);
	scene_content(INIT);
	s = scene_content(GET);
	*s = parse_scene(&json);
	scene_string(CLEAN, 0);
}

/*
** Parse the file into a t_scene variable
*/

t_scene			*scene_parse_file(const char *filename)
{
	int			scene_fd;
	t_scene		*scene;

	errno = 0;
	scene = 0;
	if ((scene_fd = open(filename, O_RDONLY)) < 0)
		perror("Error : ");
	else
	{
		parse(scene_fd);
		scene = scene_content(GET);
	}
	return (scene);
}

/*
** Destroy the scene variable
*/

void			scene_destroy(t_scene *scene)
{
	scene_content(CLEAN);
	scene = 0;
}