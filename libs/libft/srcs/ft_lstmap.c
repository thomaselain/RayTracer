/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:11:53 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:23:44 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*fresult;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	fresult = f(lst);
	result = ft_lstnew(fresult->content, fresult->content_size);
	if (result != 0)
	{
		tmp = result;
		lst = lst->next;
		while (lst)
		{
			fresult = f(lst);
			tmp->next = ft_lstnew(fresult->content, fresult->content_size);
			if (tmp->next == 0)
				return (0);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}
