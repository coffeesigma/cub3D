/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:10:28 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/07 21:24:23 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	point;

	point = 0;
	while (point < n)
	{
		if ((unsigned char)c == *(unsigned char *)(s + point))
			return ((char *)(s + point));
		point++;
	}
	return (0);
}
