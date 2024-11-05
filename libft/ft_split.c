/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:23:44 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/12 19:37:21 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcdup(const char *s1, char c)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != c)
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

static size_t	row_num(char const *s, char c)
{
	size_t	size;
	size_t	row;
	int		flag;

	flag = 1;
	row = 0;
	size = -1;
	while (s[++size])
	{
		if (s[size] != c)
		{
			if (flag)
				row++;
			flag = 0;
		}
		else
			flag = 1;
	}
	return (row);
}

static int	free_mem(char **arr, size_t row)
{
	size_t	i;
	int		is_null;

	is_null = 0;
	if (!arr[row])
	{
		is_null = 1;
		i = -1;
		while (++i < row)
			if (arr[i])
				free(arr[i]);
		free(arr);
	}
	return (is_null);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	row;
	size_t	i;

	row = row_num(s, c);
	arr = (char **)malloc(sizeof(char *) * (row + 1));
	if (!arr)
		return (0);
	row = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else
		{
			arr[row] = ft_strcdup(s + i, c);
			if (free_mem(arr, row))
				return (0);
			i += ft_strlen(arr[row]);
			row++;
		}
	}
	arr[row] = 0;
	return (arr);
}
