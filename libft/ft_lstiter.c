/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:29:03 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/15 22:32:33 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*now_lst;

	if (!lst)
		return ;
	now_lst = lst;
	while (now_lst)
	{
		(*f)(now_lst->content);
		now_lst = now_lst->next;
	}
}
