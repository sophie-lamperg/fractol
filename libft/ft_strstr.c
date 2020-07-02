/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:42:06 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/17 16:24:39 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int len_little;
	int len_big;
	int i;
	int j;

	if (*little == '\0')
		return ((char*)big);
	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	i = 0;
	while (i <= len_big - len_little)
	{
		j = 0;
		while (j < len_little && big[i + j] == little[j])
			j++;
		if (j == len_little)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
