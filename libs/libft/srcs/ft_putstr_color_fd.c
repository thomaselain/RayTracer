/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 18:46:15 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 19:11:30 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET		"\x1B[0m"

void	ft_putstr_color_fd(char const *s, char const *c, int fd)
{
	if (ft_strcmp(c, RED) == 0 || ft_strcmp(c, GRN) == 0 ||
			ft_strcmp(c, YEL) == 0 || ft_strcmp(c, BLU) == 0 ||
			ft_strcmp(c, MAG) == 0 || ft_strcmp(c, CYN) == 0 ||
			ft_strcmp(c, WHT) == 0)
		ft_putstr_fd(c, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(RESET, fd);
}
