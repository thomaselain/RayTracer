/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:42:30 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 12:58:57 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*cpy;
	unsigned char	*cpy2;

	index = 0;
	cpy = (unsigned char *)dst;
	cpy2 = (unsigned char *)src;
	while (index < n)
	{
		*cpy = *cpy2;
		cpy++;
		cpy2++;
		index++;
	}
	return (dst);
}
