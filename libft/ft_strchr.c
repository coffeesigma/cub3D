/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:28:38 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/07 21:14:01 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	point;

	point = 0;
	while (point <= ft_strlen(s))
	{
		if ((char)c == *(s + point))
			return ((char *)s + point);
		point++;
	}
	return (0);
}
