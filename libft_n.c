/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:21:31 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 11:56:55 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefl(const char *fmt, t_fmt *f)
{
	if (*fmt == 'p' ||
		((*fmt == 'x' || *fmt == 'X') && f->flag & FLAG('#') && f->u))
		return (2);
	else if (((*fmt == 'o' || *fmt == 'O') && (f->flag & FLAG('#')
		&& (((f->flag & FLAG('0') && !(f->flag & FLAG('-')) && f->prec < 0) ?
		f->width - f->l : f->prec - ft_nlenu(f->u, BASE(*fmt), 1) <= 0)
		&& (f->u != 0 || f->prec == 0))))
		|| ((*fmt == 'd' || *fmt == 'D' || *fmt == 'i')
		&& (f->flag & (FLAG(' ') | FLAG('+')) || f->i < 0)))
		return (1);
	return (0);
}

int		ft_nlenu(unsigned long long n, unsigned int b, int l)
{
	int	i;

	if (b < 2)
		return (0);
	i = 1;
	while (n / b > 0)
	{
		n /= b;
		i++;
	}
	return (i < l || (n == 0 && l == 0) ? l : i);
}

int		ft_nlenl(long long n, int b, int l)
{
	int	i;

	if (b < 2)
		return (0);
	i = 1;
	while (n / b != 0)
	{
		n /= b;
		i++;
	}
	return (i < l || (n == 0 && l == 0) ? l : i);
}

int		ft_putnbr_baseu(unsigned long long n, const char *base, int fd)
{
	unsigned int		i;
	int					r;
	unsigned long long	e;

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

int		ft_putnbr_base(long long n, const char *base, int fd)
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
	while (0 != e)
	{
		r += write(fd, &base[ABS(n / e % i)], 1);
		e /= i;
	}
	return (r);
}
