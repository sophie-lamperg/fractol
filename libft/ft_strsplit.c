/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:45:38 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/20 19:43:39 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_wc(char const *s, char c)
{
	unsigned int		wc;

	wc = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		wc++;
		while (*s && *s == c)
			s++;
	}
	return (wc);
}

static void				ft_matfree(char **str, int i)
{
	while (--i)
		free(str[i]);
	free(str);
	str = NULL;
}

char					**ft_strsplit(char const *s, char c)
{
	char				**str;
	const char			*end;
	int					i;

	i = 0;
	if (!s || !(str = (char **)malloc((ft_wc(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		end = s;
		while (*end && *end != c)
			end++;
		if (!(*(str + i++) = ft_strsub(s, 0, end - s)))
		{
			ft_matfree(str, i);
			return (NULL);
		}
		s = end;
		while (*s && *s == c)
			s++;
	}
	*(str + i) = NULL;
	return (str);
}
