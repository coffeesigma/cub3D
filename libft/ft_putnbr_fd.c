/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:46:01 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/14 16:37:27 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(unsigned int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		print_nbr(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	print_nbr(n, fd);
}
