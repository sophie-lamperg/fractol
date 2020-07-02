/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:38:40 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/18 16:45:08 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		i;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0' && i <= (int)(n - len))
	{
		if (s1[i] == s2[0])
			if (!ft_strncmp(s1 + i, s2, len))
				return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
