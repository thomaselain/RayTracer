/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:58:30 by svassal           #+#    #+#             */
/*   Updated: 2016/03/12 12:49:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen((const char *)dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	ft_strncpy(dst + dst_size, src, (int)(size - dst_size - 1));
	*(dst + size - 1) = '\0';
	return (dst_size + src_size);
}
