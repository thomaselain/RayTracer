/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:47:55 by svassal           #+#    #+#             */
/*   Updated: 2016/03/11 13:37:11 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			index;

	index = 0;
	string = (unsigned char *)s;
	while (index < n)
	{
		if (*string == (unsigned char)c)
			return ((void *)string);
		string++;
		index++;
	}
	return (0);
}
