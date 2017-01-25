/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:08:37 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 13:45:25 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cpy;

	cpy = (char *)s;
	while (*cpy != '\0')
	{
		if (*cpy == (unsigned char)c)
			return (cpy);
		cpy++;
	}
	if ((unsigned char)c == '\0')
		return (cpy);
	return (0);
}
