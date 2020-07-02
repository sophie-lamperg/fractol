/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:23:41 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/18 18:55:34 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*k;
	size_t			i;

	i = 0;
	s = (unsigned char *)dst;
	k = (unsigned char *)src;
	if (!dst && !src && (n > 0))
		return (dst);
	while (n > i)
	{
		s[i] = k[i];
		i++;
	}
	return (dst);
}
