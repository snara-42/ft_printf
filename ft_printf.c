/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2021/01/04 22:47:14 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(int fd, const char *fmt, va_list va)
{
	int		i;
	t_fmt	f;

	i = 0;
	f.r = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			f.flag = 0;
			f.width = 0;
			f.prec = -1;
			f.length = 0;
			f.tmp = 1;
			while (ft_strchr("#0- +", fmt[++i]))
			{
				f.flag |= FLAG(fmt[i]);
			}
			if (fmt[i] == '*')
			{
				i++;
				f.width = va_arg(va, int);
				f.flag |= (f.width < 0 ? FMINUS('-') : 0);
				f.width = ABS(f.width);
			}
			else
				while (ft_isdigit(fmt[i]))
				{
					f.width = 10 * f.width + fmt[i++] - '0';
				}
			if (fmt[i] == '.')
			{
				if (fmt[++i] == '*')
				{
					i++;
					f.prec = va_arg(va, int);
				}
				else
				{
					f.prec = (fmt[i] == '-' ? -1 : 0);
					while (ft_isdigit(fmt[i]))
					{
						f.prec = 10 * f.prec + fmt[i++] - '0';
					}
				}
			}
			if (fmt[i] == 'h' || fmt[i] == 'l')
			{
				f.length += (fmt[i] == 'h' ? -1 - (fmt[i + 1] == 'h') : 1 + (fmt[i + 1] == 'l'));
				i += ABS(f.length);
			}
			if (fmt[i] == 'c' || fmt[i] == '%')
			{
				f.u = (fmt[i] == '%' ? '%' : (unsigned char)va_arg(va, int));
				f.r += ft_putchar_n("0 "[!(f.flag & FZERO('0'))], (f.flag & FMINUS('-') ? 0 : --f.width), fd);
				f.r += write(fd, &f.u, 1);
				f.r += ft_putchar_n(' ', (f.flag & FMINUS('-') ? --f.width : 0), fd);
			}
			else if (fmt[i] == 's')
			{
				f.p = (char*)va_arg(va, const char*);
				f.l = ft_strnlen(f.p ? f.p : "(null)", f.prec);
				f.r += ft_putchar_n("0 "[!(f.flag & FZERO('0'))], !(f.flag & FMINUS('-')) * (f.width - f.l), fd);
				f.r += ft_putstr_n(f.p ? f.p : "(null)", f.prec, fd);
				f.r += ft_putchar_n(' ', !!(f.flag & FMINUS('-')) * (f.width - f.l), fd);
			}
			else if (fmt[i] == 'd' || fmt[i] == 'i')
			{
				f.i = va_arg(va, int);
				f.l = (f.i || f.prec) * (ft_nlen(f.i, 10, (int*)&f.tmp) + !!(f.flag & (FPLUS('+') | FSPACE(' ')) || f.i < 0));
				f.r += ft_putchar_n("0 "[!(f.flag & FZERO('0'))], !(f.flag & FMINUS('-')) * (f.width - f.prec - f.l), fd);
				f.r += write(fd, &"- +"[!(f.i < 0) * (1 + !(f.flag & FSPACE(' ')))], !!(f.flag & (FPLUS('+') | FSPACE(' ')) || f.i < 0));
				f.r += ft_putchar_n('0', (f.prec - f.l), fd);
				f.r += (f.i || f.prec) ? ft_putnbr_fd(f.i, fd) : 0;
				f.r += ft_putchar_n(' ', !!(f.flag & FMINUS('-')) * (f.width - f.l), fd);
			}
			else if (fmt[i] == 'u')
			{
				f.u = va_arg(va, unsigned int);
				f.r += ft_putnbr_baseu(f.u, "0123456789", fd);
			}
			else if (ft_strchr("oxX", fmt[i]))
			{
				f.u = va_arg(va, unsigned int);
				f.l = ft_unlen(f.u, 8 * (1 + !(fmt[i] == 'o')), ((unsigned int*)&f.tmp));
				f.r += ft_putchar_n("0 "[!(f.flag & FZERO('0'))], !(f.flag & FMINUS('-')) * (f.width - f.l), fd);
				f.r += write(fd, "0x", (f.flag & FHASH('#')) * (1 + !(fmt[i] == 'o')));
				if (fmt[i] == 'o')
					f.r += ft_putnbr_baseu(f.u, "01234567", fd);
				else if (fmt[i] == 'x')
					f.r += ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
				else if (fmt[i] == 'X')
					f.r += ft_putnbr_baseu(f.u, "0123456789ABCDEF", fd);
				f.r += ft_putchar_n(' ', !!(f.flag & FMINUS('-')) * (f.width - f.l), fd);
			}
			else if (fmt[i] == 'p')
			{
				f.flag |= FHASH('#');
				f.u = (t_ull)va_arg(va, void*);
				f.r += write(fd, "0x", 2);
				f.r += ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
			}
			else if (fmt[i] == 'n')
			{
				*va_arg(va, int*) = f.r;
			}
			i++;
		}
		else
			f.r += write(fd, &fmt[i++], 1);
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
