/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:54:59 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 00:29:54 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*list;

	if (lst && f)
	{
		if (!(temp = f(lst)))
			return (NULL);
		else
		{
			list = temp;
			while (lst->next)
			{
				lst = lst->next;
				if (!(temp->next = f(lst)))
				{
					free(temp->next);
					return (NULL);
				}
				temp = temp->next;
			}
			return (list);
		}
	}
	return (0);
}
