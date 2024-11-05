/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:03 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/05 14:59:55 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line_lst
{
	int					fd;
	char				*buffer;
	char				*line;
	struct s_line_lst	*next;
}	t_line_lst;

size_t		gnl_strlen(const char *s);
char		*gnl_strjoin(const char *s1, const char *s2, const size_t read_len);
char		*gnl_substr(char const *s, unsigned int start, size_t len);
t_line_lst	*gnl_lstnew(int fd);
size_t		check_enter(const char *line);
t_line_lst	*find_lst(t_line_lst **lst, int fd);
void		del_lst(t_line_lst **lst, int fd);
char		*make_new_line(char *buffer, char **line, size_t read_len);
char		*get_next_line(int fd);

#endif
