/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:48:42 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/13 23:55:31 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				size;
	unsigned char		*dst_str;
	const unsigned char	*src_str;

	dst_str = dst;
	src_str = src;
	if (dst_str == src_str)
		return (dst);
	size = 0;
	while (size < len)
	{
		if (dst_str > src_str)
			*(dst_str + len - size - 1) = *(src_str + len - size - 1);
		else
			*(dst_str + size) = *(src_str + size);
		size++;
	}
	return (dst);
}
