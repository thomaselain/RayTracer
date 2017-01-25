/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:13:22 by svassal           #+#    #+#             */
/*   Updated: 2016/03/05 15:20:20 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mem;
	char	*cpy;

	mem = (char *)s;
	cpy = (char *)s;
	while (*cpy != '\0')
		cpy++;
	while (cpy != mem)
	{
		if ((unsigned char)c == *cpy)
			return (cpy);
		cpy--;
	}
	if (*cpy == (unsigned char)c)
		return (cpy);
	return (0);
}
