/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:13:08 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/17 20:12:40 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *dtr;
	char sym;

	dtr = (char*)str;
	sym = (char)ch;
	while (*dtr && *dtr != sym)
	{
		dtr++;
	}
	return ((*dtr == ch) ? dtr : NULL);
}
