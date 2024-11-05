/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:29:12 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:49 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strndup(char const *s1, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && len < n)
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = -1;
	while (++i < len)
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	front;
	size_t	back;

	front = 0;
	back = 0;
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	i = -1;
	while (++i < ft_strlen(s1))
	{
		if (is_set(s1[i], set))
			front++;
		else
			break ;
	}
	i = ft_strlen(s1);
	while (i-- > front)
	{
		if (is_set(s1[i], set))
			back++;
		else
			break ;
	}
	return (ft_strndup(s1 + front, ft_strlen(s1) - front - back));
}
