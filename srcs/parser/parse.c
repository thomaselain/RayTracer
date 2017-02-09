/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:22:31 by svassal           #+#    #+#             */
/*   Updated: 2017/02/09 16:30:28 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <parse_major.h>
#include <stdio.h>
#define GET		0
#define INIT	1
#define CLEAN	2
#define SET		3

/*
** Write the second string over the first one
*/

static void		str_write_over(char **s1, char *s2)
{
	ft_strdel(s1);
	*s1 = ft_strdup(s2);
	ft_strdel(&s2);
}

/*
** Parse the file given as filedescriptor
*/

static void		parse(int fd)
{
	char	*json;
	char	*tmp;
	int		ret;
	t_scene	*s;

	json = 0;
	tmp = 0;
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		str_write_over(&tmp, ft_strtrim(tmp));
		if (json == 0)
			json = ft_strdup(tmp);
		else
			str_write_over(&json, ft_strjoin(json, tmp));
		if (tmp != 0)
			ft_strdel(&tmp);
	}
	close(fd);
	scene_string(SET, json);
	scene_content(INIT);
	s = scene_content(GET);
	*s = parse_scene(&json);
	scene_string(CLEAN, 0);
}

/*
** Returns 0 if the extension of the file is .json, otherwise the function will return -1
*/

int				check_extension(const char *filename)
{
	ft_strrev((char*)filename);
	if (ft_strnstr(filename, "nosj.", 5))
	{
		ft_strrev((char*)filename);
		return (0);
	}
	return (-1);
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
	if (check_extension((char*)filename) == -1)
	{
		ft_putendl("Wrong format. Use the '.json' format.");
		exit(0);
	}
	if ((scene_fd = open(filename, O_RDONLY)) < 0)
	{
		perror("Error : ");
		exit(0);
	}
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
