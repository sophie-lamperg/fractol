/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:10:09 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/18 15:21:08 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	node = *alst;
	while (node)
	{
		next = node->next;
		del(node->content, node->content_size);
		free(node);
		node = next;
	}
	*alst = NULL;
}
