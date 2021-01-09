/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2021/01/10 02:00:39 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(int fd, const char *fmt, va_list va)
{
	int		i;
	t_fmt	f;

	i = 0;
	f.r = 0;
	while (fmt && *fmt != '\0')
	{
		if (*fmt == '%')
		{
			f.flag = 0;
			f.width = 0;
			f.prec = -1;
			f.length = 0;
			f.t = 0;
			while (ft_strchr("#0- +", *++fmt))
				f.flag |= FLAG(*fmt);
			if (*fmt == '*')
			{
				f.width = va_arg(va, int);
				f.flag |= (f.width < 0 ? FMINUS('-') : 0);
				f.width = ABS(f.width);
				fmt++;
			}
			else
				while ('0' <= *fmt && *fmt <= '9')
					f.width = 10 * f.width + *fmt++ - '0';
			if (*fmt == '.' && fmt[1] == '*')
			{
				f.prec = va_arg(va, int);
				fmt += 2;
			}
			else if (*fmt == '.')
			{
				f.prec = (*++fmt == '-' ? -1 : 0);
				while ('0' <= *fmt && *fmt <= '9')
					f.prec = 10 * f.prec + *fmt++ - '0';
			}
			if (*fmt == 'c' || *fmt == '%')
			{
				f.u = (*fmt == '%' ? '%' : (unsigned char)va_arg(va, int));
				f.r += ft_putcharn("0 "[!(f.flag & FZERO('0'))], (f.flag & FMINUS('-') ? 0 : --f.width), fd);
				f.r += write(fd, &f.u, 1);
				f.r += ft_putcharn(' ', (f.flag & FMINUS('-') ? --f.width : 0), fd);
			}
			else if (*fmt == 's')
			{
				f.p = va_arg(va, char*);
				f.l = ft_strnlen(f.p ? f.p : "(null)", f.prec);
				f.r += ft_putcharn("0 "[!(f.flag & FZERO('0'))], !(f.flag & FMINUS('-')) * (f.width - f.l), fd);
				f.r += ft_putstrn(f.p ? f.p : "(null)", f.prec, fd);
				f.r += ft_putcharn(' ', !!(f.flag & FMINUS('-')) * (f.width - f.l), fd);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				f.i = va_arg(va, int);
				f.l = ft_nlen(f.i, 10, f.prec) + !!(f.flag & (FPLUS('+') | FSPACE(' ')) || f.i < 0);
				f.t += ft_putcharn(' ', !((f.flag & FMINUS('-')) || (f.flag & FZERO('0') && f.prec < 0)) * (f.width - f.l), fd);
				f.t += write(fd, &"- +"[!(f.i < 0) * (1 + !(f.flag & FSPACE(' ')))], !!((f.flag & (FPLUS('+') | FSPACE(' '))) || f.i < 0));
				f.t += ft_putcharn('0', ((f.flag & FZERO('0') && !(f.flag & FMINUS('-')) && f.prec < 0) ? f.width - f.l : f.prec - ft_nlen(f.i, 10, 1)), fd);
				f.t += (f.i || f.prec) ? ft_putnbr_base(f.i, "0123456789", fd) : 0;
				f.t += ft_putcharn(' ', !!(f.flag & FMINUS('-')) * (f.width - f.t), fd);
				f.r += f.t;
			}
			else if (*fmt == 'u')
			{
				f.u = va_arg(va, unsigned int);
				f.r += ft_putnbr_baseu(f.u, "0123456789", fd);
			}
			else if (ft_strchr("oxX", *fmt))
			{
				f.u = va_arg(va, unsigned int);
				f.l = ft_nlenu(f.u, 8 * (1 + !(*fmt == 'o')), f.prec);
				f.r += ft_putcharn("0 "[!(f.flag & FZERO('0'))], !(f.flag & FMINUS('-')) * (f.width - f.l), fd);
				f.r += write(fd, "0x", (f.flag & FHASH('#')) * (1 + !(*fmt == 'o')));
				if (*fmt == 'o')
					f.r += ft_putnbr_baseu(f.u, "01234567", fd);
				else if (*fmt == 'x')
					f.r += ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
				else if (*fmt == 'X')
					f.r += ft_putnbr_baseu(f.u, "0123456789ABCDEF", fd);
				f.r += ft_putcharn(' ', !!(f.flag & FMINUS('-')) * (f.width - f.l), fd);
			}
			else if (*fmt == 'p')
			{
				f.flag |= FHASH('#');
				f.u = (t_ull)va_arg(va, void*);
				f.r += write(fd, "0x", 2);
				f.r += ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
			}
			else if (*fmt == 'n')
			{
				*va_arg(va, int*) = f.r;
			}
		}
		else
			f.r += write(fd, fmt, 1);
		fmt++;
	}
	return (f.r);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	va;
	int		r;

	va_start(va, fmt);
	r = ft_vfprintf(1, fmt, va);
	va_end(va);
	return (r);
}
