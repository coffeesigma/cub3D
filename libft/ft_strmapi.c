/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:13:09 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/13 23:32:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_str;
	size_t	i;

	f_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!f_str)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		f_str[i] = (*f)(i, s[i]);
		i++;
	}
	f_str[i] = '\0';
	return (f_str);
}
