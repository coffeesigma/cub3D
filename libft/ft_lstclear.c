/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:19:59 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/15 22:28:31 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now_lst;
	t_list	*next_lst;

	if (!lst || !(*lst))
		return ;
	now_lst = *lst;
	while (now_lst)
	{
		next_lst = now_lst->next;
		ft_lstdelone(now_lst, (*del));
		now_lst = next_lst;
	}
	*lst = 0;
}
