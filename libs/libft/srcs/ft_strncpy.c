/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:26:27 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 15:35:05 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;
	char	*mem;

	index = 0;
	mem = dst;
	while (index < len && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		index++;
	}
	if (index < len)
		while (index < len)
		{
			*dst = '\0';
			dst++;
			index++;
		}
	return (mem);
}
