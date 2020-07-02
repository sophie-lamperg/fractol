/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:33:29 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/20 20:16:49 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void *str;

	if ((size + 1) < size)
		return (NULL);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return ((char*)str);
}
