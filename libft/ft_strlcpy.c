/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:47:20 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/06 20:43:47 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	change_size;

	change_size = 0;
	while (change_size + 1 < dstsize && src[change_size])
	{
		dst[change_size] = src[change_size];
		change_size++;
	}
	if (dstsize > 0)
		dst[change_size] = '\0';
	return (ft_strlen(src));
}
