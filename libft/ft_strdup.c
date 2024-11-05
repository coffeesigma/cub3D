/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:45:28 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/08 18:04:20 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
