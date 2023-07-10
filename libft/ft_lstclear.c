/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:44 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/11 16:11:48 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*this function takes as parameters lst, the address of a pointer to a node, 
and del, the address of the funciton used to delete the content of the node. 
Deletes and frees the given node and every successfor of that node, using the
function del and free. The pointer to the list must be set to null*/
/* check if my version works too (first one is mine)
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		del(tmp);
		tmp = tmp->next;
	}
	tmp->next = NULL;
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = NULL;
}
