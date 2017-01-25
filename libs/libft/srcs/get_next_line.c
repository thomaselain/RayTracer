/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:21:08 by svassal           #+#    #+#             */
/*   Updated: 2016/05/31 12:00:15 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		join(char **str, char *mem)
{
	char		*ptr;

	ptr = *str;
	if ((*str = ft_strjoin(*str, mem)) == 0)
	{
		free(ptr);
		return (-1);
	}
	free(ptr);
	return (1);
}

static int		ft(int i, char **str, char **line)
{
	char		*ptr;

	if ((*line = ft_strnew(i)) == 0)
		return (-1);
	ft_strncpy(*line, *str, i);
	if ((*str)[i + 1] == '\0')
		ft_strdel(str);
	else
	{
		ptr = *str;
		if ((*str = ft_strsub(*str, i + 1, ft_strlen(*str + i))) == 0)
		{
			free(ptr);
			return (-1);
		}
		free(ptr);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*mem;
	char		tmp[BUFF_SIZE + 1];
	int			i;

	if (line == 0)
		return (-1);
	while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[i] = '\0';
		if (mem == 0)
		{
			if ((mem = ft_strdup(tmp)) == 0)
				return (-1);
		}
		else if (join(&mem, tmp) == -1)
			return (-1);
		if (ft_strchr(mem, '\n') != 0)
			break ;
	}
	if ((mem == 0) || (i < 0))
		return (i);
	i = 0;
	while ((mem[i] != '\0') && (mem[i] != '\n'))
		++i;
	return (ft(i, &mem, line));
}
