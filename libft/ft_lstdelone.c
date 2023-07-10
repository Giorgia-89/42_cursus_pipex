/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:28:03 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/11 15:46:25 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*this function takes as parameter a node and the address of the function del. 
Frees the memory
of the contents of that node using the function del. The memory of next must 
not be freed
returns nothing. 
Authorised functions: free*/
/*
void	del(t_list *lst)
{
	if (!lst)
		return ;
	free (lst->content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst);
}*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
