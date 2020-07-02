/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:32:21 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/17 16:15:47 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	while (app[i] != '\0' && i < n)
	{
		dest[len + i] = app[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
