/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:09:40 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/12 12:22:56 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (ft_strlen(s) > len + start)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else if (ft_strlen(s) > start)
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub = (char *)malloc(sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && i + start < ft_strlen(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
