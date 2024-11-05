/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:00 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/05 14:59:55 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_enter(const char *line)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = gnl_strlen(line);
	while (i < line_size)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

t_line_lst	*find_lst(t_line_lst **lst, int fd)
{
	t_line_lst	*find_lst;

	if (!(*lst))
	{
		*lst = gnl_lstnew(fd);
		return (*lst);
	}
	find_lst = *lst;
	while (1)
	{
		if (find_lst->fd == fd)
		{
			find_lst->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
			return (find_lst);
		}
		if (!(find_lst->next))
		{
			find_lst->next = gnl_lstnew(fd);
			return (find_lst->next);
		}
		find_lst = find_lst->next;
	}
}

void	del_lst(t_line_lst **lst, int fd)
{
	t_line_lst	*now_lst;
	t_line_lst	*next_lst;

	if (!lst || !(*lst))
		return ;
	now_lst = *lst;
	if (now_lst->fd == fd)
	{
		*lst = now_lst->next;
		free(now_lst->line);
		free(now_lst);
		return ;
	}
	while (now_lst)
	{
		next_lst = now_lst->next;
		if (next_lst->fd == fd)
		{
			now_lst->next = next_lst->next;
			free(next_lst->line);
			free(next_lst);
			return ;
		}
		now_lst = next_lst;
	}
}

char	*make_new_line(char *buffer, char **line, size_t read_len)
{
	char	*comb_line;
	char	*new_line;
	size_t	enter;

	comb_line = gnl_strjoin(*line, buffer, read_len);
	enter = check_enter(comb_line);
	free(*line);
	*line = 0;
	if (enter < gnl_strlen(comb_line) || read_len == 0)
	{
		new_line = gnl_substr(comb_line, 0, enter);
		if (new_line)
			*line = gnl_substr(comb_line, enter + 1,
					gnl_strlen(comb_line) - enter - 1);
		free(comb_line);
		comb_line = 0;
		return (new_line);
	}
	*line = comb_line;
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line_lst		*line_lst;
	t_line_lst				*now_line;
	ssize_t					read_len;
	char					*new_line;

	now_line = find_lst(&line_lst, fd);
	if (!now_line)
		return (0);
	read_len = 1;
	while (read_len > 0 || now_line->line)
	{
		read_len = read(fd, now_line->buffer, BUFFER_SIZE);
		if (read_len < 0)
			break ;
		new_line = make_new_line(now_line->buffer, &(now_line->line), read_len);
		if (new_line)
		{
			free(now_line->buffer);
			return (new_line);
		}
	}
	free(now_line->buffer);
	del_lst(&line_lst, fd);
	return (0);
}
