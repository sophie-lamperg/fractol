/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:21:17 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/20 20:22:48 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *p;

	p = ((char*)malloc((ft_strlen(str) + 1) * sizeof(char)));
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, str);
	return (p);
}
