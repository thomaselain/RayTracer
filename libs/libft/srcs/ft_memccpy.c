/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:55:25 by svassal           #+#    #+#             */
/*   Updated: 2016/03/11 11:56:57 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*d;
	unsigned char	*s;

	index = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (index < n && *s != (unsigned char)c)
	{
		*d = *s;
		d++;
		s++;
		index++;
	}
	if (*s == (unsigned char)c)
	{
		*d = *s;
		return (d + 1);
	}
	return (0);
}
