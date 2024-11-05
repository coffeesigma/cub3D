/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:33:42 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/17 01:35:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*now_lst;
	t_list	*temp_lst;
	void	*temp_content;

	if (!lst)
		return (0);
	new_lst = 0;
	now_lst = lst;
	while (now_lst)
	{
		temp_content = (*f)(now_lst->content);
		temp_lst = ft_lstnew(temp_content);
		if (!temp_lst)
		{
			ft_lstclear(&new_lst, (*del));
			(*del)(temp_content);
			return (0);
		}
		now_lst = now_lst->next;
		ft_lstadd_back(&new_lst, temp_lst);
	}
	return (new_lst);
}
