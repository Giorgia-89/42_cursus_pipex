/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:11:24 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/11 16:11:25 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*this function takes a parameters lst, the address of a pointer to a node,
f, the address of the function  used to iterate on the list, and del, the 
address of the function used to delete the content of a node if needed
Returns the new list, or NULL if the allocation fails. 
Iterates the list lst and applies the function f on the content of each node.
Creates a new list resulting of the successive applications of the function f.
The del function is used to delete the content of a node if needed
Need to:
-initialise two pointers, one temporary for hte nodes and one to which we will
allocate the new list. 
If the lst is empty, return 0. otherwise, initialise newlist to 0.
while lst is not empty, newnode becomes the result of ft_lstnew (on the lst 
contents)
and if it is empty the list is cleared. Otherwise, we run the addback function
on the new node (using newlist as first para) and then point lst to the next.*/
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**newlist;
	t_list	*newnode;

	while (lst != NULL)
	{
		newnode = f(lst->content);
		lst = lst->next;
		*newlist = newnode;
	}
	return (*newlist);
}*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst)
		return (0);
	newlist = 0;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
