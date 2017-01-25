/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:02:31 by svassal           #+#    #+#             */
/*   Updated: 2016/03/04 17:31:52 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*ss1;
	unsigned char	*ss2;

	index = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (index < n)
	{
		if (*ss1 < *ss2 || *ss1 > *ss2)
			return (*ss1 - *ss2);
		index++;
		ss1++;
		ss2++;
	}
	return (0);
}
