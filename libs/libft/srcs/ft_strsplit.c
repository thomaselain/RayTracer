/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:15 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 10:56:32 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		trig;

	i = 0;
	trig = 0;
	while (*s != '\0')
	{
		if (trig == 0 && *s != c)
		{
			trig = 1;
			i++;
		}
		if (trig == 1 && *s == c)
			trig = 0;
		s++;
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**n_str;
	int		nb_word;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	nb_word = count_words(s, c);
	if ((n_str = (char **)malloc(sizeof(char *) * (nb_word + 1))) == 0)
		return (0);
	while (nb_word > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		n_str[i] = ft_strsub(s, 0, word_len(s, c));
		if (n_str[i] == 0)
			return (0);
		s = s + word_len(s, c);
		i++;
		nb_word--;
	}
	n_str[i] = 0;
	return (n_str);
}
