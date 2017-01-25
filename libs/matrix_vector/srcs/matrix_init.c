/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:25:25 by svassal           #+#    #+#             */
/*   Updated: 2016/10/16 14:52:32 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** Init each element of the matrix according to a defined patern,
** thes ones with the same X and Y coordinate at 1, and the others to 0
*/

void			init_matrix_id(t_matrix4f *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j == i)
				m->data[i][j] = 1;
			else
				m->data[i][j] = 0;
		}
	}
}

/*
** Create a matrix, allocating enough memory for it
*/

t_matrix4f		*make_matrix()
{
	t_matrix4f		*r;

	if ((r = malloc(sizeof(t_matrix4f))) == 0)
		return (0);
	init_matrix_id(r);
	return (r);
}

/*
** Delete a matrix, freeing the memory alloacted for it
*/

void			delete_matrix(t_matrix4f *m)
{
	if (m != 0)
		free(m);
	m = 0;
}

/*
** Replace the existing "dest" matrix (freeing it) by the src one
*/

void			write_over_matrix(t_matrix4f *dest, t_matrix4f *src)
{
	if (src != 0)
	{
		delete_matrix(dest);
		dest = src;
	}
	src = 0;
}
