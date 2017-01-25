/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:20:26 by svassal           #+#    #+#             */
/*   Updated: 2015/11/30 18:28:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_elem;

	if ((n_elem = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	if (content == 0)
	{
		n_elem->content = 0;
		n_elem->content_size = 0;
	}
	else
	{
		if ((n_elem->content = malloc(content_size)) == 0)
			return (0);
		n_elem->content = ft_memcpy(n_elem->content, content, content_size);
		n_elem->content_size = content_size;
	}
	n_elem->next = 0;
	return (n_elem);
}
