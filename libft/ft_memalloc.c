/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:44:35 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/17 16:59:42 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	char	*reschar;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (res == NULL)
		return (NULL);
	reschar = (char*)res;
	while (i < size)
	{
		reschar[i] = '\0';
		i++;
	}
	return (res);
}
