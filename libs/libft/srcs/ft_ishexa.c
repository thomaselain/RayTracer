/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 17:41:35 by svassal           #+#    #+#             */
/*   Updated: 2016/11/24 11:54:42 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(int c)
{
	if (ft_toupper(c) >= 'A' && ft_toupper(c) <= 'F')
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	return (0);
}
