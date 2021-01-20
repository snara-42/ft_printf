/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:23:41 by snara             #+#    #+#             */
/*   Updated: 2021/01/21 03:52:43 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flen(long double n, int b, int l)
{
	int		i;

	i = 0;
	if (b < 2)
		return (0);
	while (1 <= ABS(n))
	{
		n /= b;
		i++;
	}
	return (i + l);
}

char	*ft_ftoa(long double n, t_fmt *f, const char *base)
{
	const t_ld	c = n;
	int			i;
	int			b;

	b = 0;
	i = F_INT + 1;
	while (base[b])
		b++;
	f->a[i + 1] = '\0';
	f->a[i] = '.';
	while (0 < i--)
	{
		f->a[i] = base[(t_um)ABS(n) % b];
		n /= b;
	}
	n = c;
	i = F_INT + 1;
	while (i++ < F_INT + F_FRAC)
	{
		n = ABS(n - (t_um)(n));
		f->a[i] = base[(t_um)ABS(n * b) % b];
		n = ABS(n * b - (t_um)(n * b));
		f->a[i + 1] = '\0';
	}
	return (f->a);
}

/*
**int main(void){static t_fmt f;
**f.u = 0x0000000000000001;f.f = *(double*)&(f.u);
**ft_printf("%i: %s", ft_flen(f.f, 10, 0), ft_ftoa(f.f, &f, "01"));
**return (0);}
*/
