/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:18:29 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/13 18:10:20 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	alloc_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	put_num(unsigned int n, char *arr, size_t point)
{
	if (n > 0)
	{
		arr[point] = (n % 10) + '0';
		put_num(n / 10, arr, point - 1);
	}
}

char	*ft_itoa(int n)
{
	char	*num_arr;
	size_t	len;

	len = alloc_len(n);
	num_arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!num_arr)
		return (0);
	if (n < 0)
	{
		num_arr[0] = '-';
		put_num(-n, num_arr, len - 1);
	}
	else if (n == 0)
		num_arr[0] = '0';
	else
		put_num(n, num_arr, len - 1);
	num_arr[len] = '\0';
	return (num_arr);
}
