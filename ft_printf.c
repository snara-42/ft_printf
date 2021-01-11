/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2021/01/12 04:50:33 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*fmt_init(t_fmt *f)
{
	f->flag = 0;
	f->width = 0;
	f->prec = -1;
	f->length = 0;
	f->t = 0;
	f->l = 0;
	f->p = 0;
	f->i = 0;
	f->u = 0;
	f->f = 0;
	return (f);
}

char	*fmt_parse(t_fmt *f, const char *fmt, char **c, va_list va)
{
	fmt_init(f);
	while (ft_strchr("#0- +", *++fmt))
		f->flag |= FLAG(*fmt);
	if (*fmt == '*')
	{
		f->width = va_arg(va, int);
		f->flag |= (f->width < 0 ? FLAG('-') : 0);
		f->width = ABS(f->width) + 0 * *fmt++;
	}
	else
		while ('0' <= *fmt && *fmt <= '9')
			f->width = 10 * f->width + *fmt++ - '0';
	if (*fmt == '.' && fmt[1] == '*')
	{
		f->prec = va_arg(va, int);
		fmt += 2;
	}
	else if (*fmt == '.')
	{
		f->prec = (*++fmt == '-' ? -1 : 0);
		fmt += (*fmt == '-' || *fmt == '+') ? 1 : 0;
		while ('0' <= *fmt && *fmt <= '9')
			f->prec = 10 * f->prec + *fmt++ - '0';
	}
	return ((*c = (char*)fmt));
}

int		ft_vfprintf(int fd, const char *fmt, va_list va)
{
	t_fmt	f;

	f.r = 0;
	while (fmt && *fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt_parse(&f, fmt, (char**)&fmt, va);
			if (*fmt == 'c' || *fmt == '%')
			{
				f.u = (*fmt == '%' ? '%' : (unsigned char)va_arg(va, int));
				f.r += ft_putcharn("0 "[!(f.flag & FLAG('0'))], (f.flag & FLAG('-') ? 0 : --f.width), fd);
				f.r += write(fd, &f.u, 1);
				f.r += ft_putcharn(' ', (f.flag & FLAG('-') ? --f.width : 0), fd);
			}
			else if (*fmt == 's')
			{
				f.p = va_arg(va, char*);
				f.l = ft_putstrn(f.p ? f.p : "(null)", f.prec, -1);
				f.r += ft_putcharn("0 "[!(f.flag & FLAG('0'))], !(f.flag & FLAG('-')) * (f.width - f.l), fd);
				f.r += ft_putstrn(f.p ? f.p : "(null)", f.prec, fd);
				f.r += ft_putcharn(' ', !!(f.flag & FLAG('-')) * (f.width - f.l), fd);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				f.i = va_arg(va, int);
				f.l = ft_nlen(f.i, BASE(*fmt), f.prec) + PREFLS(*fmt);
				f.t += ft_putcharn(' ', !((f.flag & FLAG('-')) || (f.flag & FLAG('0') && f.prec < 0)) * (f.width - f.l), fd);
				f.t += write(fd, PREFX(*fmt), PREFL(*fmt));
				f.t += ft_putcharn('0', ((f.flag & FLAG('0') && !(f.flag & FLAG('-')) && f.prec < 0) ? f.width - f.l : f.prec - ft_nlen(f.i, 10, 1)), fd);
				f.t += f.i || f.prec ? ft_putnbr_base(f.i, "0123456789", fd) : 0;
				f.t += ft_putcharn(' ', !!(f.flag & FLAG('-')) * (f.width - f.t), fd);
				f.r += f.t;
			}
			else if (ft_strchr("pouxX", *fmt))
			{
				f.u = *fmt != 'p' ? va_arg(va, t_ui) : (t_ull)va_arg(va, void*);
				f.l = PREFL(*fmt) + ft_nlenu(f.u, BASE(*fmt), f.prec);
				f.t += ft_putcharn(' ', !((f.flag & FLAG('-')) || (f.flag & FLAG('0') && f.prec < 0)) * (f.width - f.l), fd);
				f.t += write(fd, PREFX(*fmt), PREFL(*fmt));
				f.t += ft_putcharn('0', ((f.flag & FLAG('0') && !(f.flag & FLAG('-'))) && f.prec < 0 ? f.width - f.l : f.prec - ft_nlenu(f.u, BASE(*fmt), 1)), fd);
				if (*fmt == 'o')
					f.t += !(f.u || f.prec || f.flag & FLAG('#')) ? 0 : ft_putnbr_baseu(f.u, "01234567", fd);
				else if (*fmt == 'u')
					f.t += !(f.u || f.prec) ? 0 : ft_putnbr_baseu(f.u, "0123456789", fd);
				else if (*fmt == 'x' || *fmt == 'p')
					f.t += !(f.u || f.prec) ? 0 : ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
				else if (*fmt == 'X')
					f.t += !(f.u || f.prec) ? 0 : ft_putnbr_baseu(f.u, "0123456789ABCDEF", fd);
				f.t += ft_putcharn(' ', !!(f.flag & FLAG('-')) * (f.width - f.t), fd);
				f.r += f.t;
			}
			else if (*fmt == 'n')
				*va_arg(va, int*) = f.r;
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
