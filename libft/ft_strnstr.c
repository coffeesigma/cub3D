/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:42:31 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/07 22:09:53 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	hay_len;
	size_t	needle_len;

	hay_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	while (i + needle_len <= hay_len && i + needle_len <= len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
