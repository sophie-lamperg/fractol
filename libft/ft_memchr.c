/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:50:05 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/17 19:16:17 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char k;

	a = (unsigned char *)s;
	k = (unsigned char)c;
	while (n--)
	{
		if (*a == k)
			return (a);
		a++;
	}
	return (NULL);
}
