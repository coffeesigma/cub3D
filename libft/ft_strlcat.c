/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:50:24 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/06 21:02:51 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	add_size;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	add_size = 0;
	while (add_size + dst_size + 1 < dstsize && src[add_size])
	{
		dst[dst_size + add_size] = src[add_size];
		add_size++;
	}
	dst[dst_size + add_size] = '\0';
	if (dst_size < dstsize)
		return (src_size + dst_size);
	else
		return (src_size + dstsize);
}
