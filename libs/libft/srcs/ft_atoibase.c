/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:05:46 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 10:53:00 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcalc(char c, int b, char *base)
{
	int		index;

	index = 0;
	if (c == '\0')
		return (-1);
	while (c != base[index] && index < b)
		index++;
	if (index == b)
		return (-1);
	return (index);
}

int			ft_atoibase(const char *s, int b)
{
	char	*base;
	int		sign;
	int		res;
	int		num;

	res = 0;
	sign = 1;
	num = 0;
	base = "0123456789ABCDEF";
	while (ft_iswhitespace((int)*s) == 1)
		s++;
	if (*s == '+' || *s == '-')
	{
		sign = (*s == '-') ? -1 : 1;
		s++;
	}
	while ((num = ft_numcalc((char)ft_toupper((int)*s), b, base)) != -1)
	{
		res = (res * b) + num;
		s++;
	}
	return (res * sign);
}
