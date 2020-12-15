/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:50:50 by snara             #+#    #+#             */
/*   Updated: 2020/12/15 18:21:39 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) (((x) < 0) ? (-x) : (x))

int	ft_putnbr_fd(int n, int fd)
{
	const int	b = 10;
	const char	d[b] = "0123456789";
	int			e;
	int			r;

	e = 1;
	r = 0;
	while (e <= (n < 0 ? -(n / b) : (n / b)))
		e *= b;
	write(fd, "-", (n < 0 ? 1 : 0));
	while (0 < e)
	{
		r += write(fd, &d[n < 0 ? -(n / e % b) : (n / e % b)], 1);
		e /= b;
	}
	return (r);
}

int	ft_putnbr_baseu(unsigned int n, char *base, int fd)
{
	int				i;
	int				j;
	unsigned int	e;

	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (0 < j--)
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (0);
	}
	if (i < 2)
		return (0);
	e = 1;
	while (e <= ABS(n / i))
		e *= i;
	write(1, "-", (n < 0 ? 1 : 0));
	while (0 < e)
	{
		j += write(fd, &base[ABS(n / e % i)], 1);
		e /= i;
	}
	return (j);
}

int	ft_putnbr_base(int n, char *base, int fd)
{
	int			i;
	int			j;
	int			e;

	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (0 < j--)
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (0);
	}
	if (i < 2)
		return (0);
	e = -1;
	while (e >= (n < 0 ? (n / i) : -(n / i)))
		e *= i;
	write(1, "-", (n < 0 ? 1 : 0));
	while (0 > e)
	{
		j += write(fd, &base[n < 0 ? (n / e % i) : -(n / e % i)], 1);
		e /= i;
	}
	return (j);
}

/*
**int main(){int n=INT_MIN;ft_putnbr_fd(n,1);ft_putnbr_base(n,"01",1);return 0;}
*/
