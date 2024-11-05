/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:07 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/05 15:00:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strjoin(const char *s1, const char *s2, const size_t read_len)
{
	char	*join;
	size_t	i;
	size_t	s1_len;

	s1_len = gnl_strlen(s1);
	if (s1_len + read_len <= 0)
		return (0);
	join = (char *)malloc(sizeof(char) * (s1_len + read_len + 1));
	if (!join)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < s1_len + read_len)
	{
		join[i] = s2[i - s1_len];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	s_len;

	s_len = gnl_strlen(s);
	if (!s)
		return (0);
	if (s[len + start] == '\n')
		len++;
	if (!len)
		return (0);
	if (s_len > len + start)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else if (s_len > start)
		sub = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		sub = (char *)malloc(sizeof(char));
	if (!sub)
		return (0);
	i = -1;
	while (++i < len && i + start < s_len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

t_line_lst	*gnl_lstnew(int fd)
{
	t_line_lst	*new_node;

	new_node = (t_line_lst *)malloc(sizeof(t_line_lst));
	if (!new_node)
		return (0);
	new_node->fd = fd;
	new_node->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!new_node->buffer)
	{
		free(new_node);
		return (0);
	}
	new_node->line = 0;
	new_node->next = 0;
	return (new_node);
}
