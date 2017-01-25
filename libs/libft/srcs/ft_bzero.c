/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:35:11 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 13:12:57 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cpy;
	size_t			index;

	index = 0;
	cpy = (unsigned char *)s;
	while (index < n)
	{
		*cpy = 0;
		cpy++;
		index++;
	}
}
