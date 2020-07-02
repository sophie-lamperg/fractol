/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:16:12 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/18 17:01:49 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
		j++;
	if (n <= i)
		j += n;
	else
		j += i;
	k = 0;
	while (src[k] && i + 1 < n)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}
