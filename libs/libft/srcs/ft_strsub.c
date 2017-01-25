/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:53:51 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:12:42 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned char	*to_ret;
	unsigned char	*to_cpy;
	unsigned char	*mem;

	if (s == 0)
		return (0);
	if ((to_ret = malloc(sizeof(unsigned char) * (len + 1))) == 0)
		return (0);
	mem = to_ret;
	to_cpy = (unsigned char *)s;
	to_cpy = to_cpy + start;
	while (len > 0)
	{
		*to_ret = *to_cpy;
		to_ret++;
		to_cpy++;
		len--;
	}
	*to_ret = '\0';
	return ((char *)mem);
}
