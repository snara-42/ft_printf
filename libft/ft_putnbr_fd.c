/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:50:50 by snara             #+#    #+#             */
/*   Updated: 2020/11/11 09:43:34 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	const int	b = 10;
	const char	d[b] = "0123456789";
	int			e;

	e = 1;
	while (e < (n < 0 ? -(n / b) : (n / b)))
		e *= b;
	write(fd, "-", (n < 0 ? 1 : 0));
	while (0 < e)
	{
		write(fd, &d[n < 0 ? -(n / e % b) : (n / e % b)], 1);
		e /= b;
	}
}

/*
**int main(){int n=-2147483648;ft_putnbr_fd(n,1);return 0;}
*/
