/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:17:51 by svassal           #+#    #+#             */
/*   Updated: 2015/11/29 13:42:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*n_ptr;

	if ((n_ptr = malloc(sizeof(size_t) * size)) == 0)
		return (0);
	ft_bzero(n_ptr, size);
	return (n_ptr);
}
