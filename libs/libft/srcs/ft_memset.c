/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:15:53 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 12:55:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;
	size_t			index;

	index = 0;
	mem = (unsigned char *)b;
	while (index < len)
	{
		*mem = (unsigned char)c;
		mem++;
		index++;
	}
	return (b);
}
