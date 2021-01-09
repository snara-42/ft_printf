/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:32:24 by snara             #+#    #+#             */
/*   Updated: 2021/01/10 00:25:22 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		else if (*s == '\0')
			return (NULL);
		s++;
	}
}

int		ft_nlenu(unsigned int n, unsigned int b, int l)
{
	int	i;

	if (b < 2)
		return (0);
	i = 1;
	while ((n /= b) > 0)
	{
		i++;
	}
	return (i < l || n == 0 ? l : i);
}

int		ft_nlen(int n, int b, int l)
{
	int	i;

	if (b < 2)
		return (0);
	i = 1;
	while (n / b)
	{
		n /= b;
		i++;
	}
	return (i < l || (n == 0 && l == 0) ? l : i);
}

int	ft_putnbr_baseu(t_ull n, const char *base, int fd)
{
	unsigned int	i;
	int				r;
	t_ull			e;

	i = 0;
	r = 0;
	while (base[i] != '\0')
		i++;
	if (i < 2)
		return (0);
	e = 1;
	while (e <= (n / i))
		e *= i;
	while (0 < e)
	{
		r += write(fd, &base[ABS(n / e % i)], 1);
		e /= i;
	}
	return (r);
}

int	ft_putnbr_base(long long n, const char *base, int fd)
{
	int			i;
	int			r;
	long long	e;

	i = 0;
	r = 0;
	while (base[i] != '\0')
		i++;
	if (i < 2)
		return (0);
	e = -1;
	while (e >= -ABS(n / i))
		e *= i;
	while (e < 0)
	{
		r += write(fd, &base[ABS(n / e % i)], 1);
		e /= i;
	}
	return (r);
}

int	ft_putcharn(char c, int n, int fd)
{
	int	r;

	r = 0;
	while (0 < n--)
		r += write(fd, &c, 1);
	return (r);
}

int	ft_strnlen(const char *s, int n)
{
	int	i;

	i = 0;
	while ((i < n || n < 0) && s[i])
		i++;
	return (i);
}

int	ft_putstrn(char *s, int n, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (write(fd, s, i < n || n < 0 ? i : n));
}
