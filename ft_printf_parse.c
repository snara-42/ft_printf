/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 01:53:29 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 03:01:32 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fmt_init(t_fmt *f)
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
}

static void	fmt_argn(t_fmt *f, const char *fmt, va_list va)
{
	if (*fmt == 'n')
		*va_arg(va, int*) = (int)f->r;
	else if (ft_strnc("lln", fmt, 3, ' '))
		*va_arg(va, long long*) = f->r;
	else if (ft_strnc("ln", fmt, 2, ' '))
		*va_arg(va, long*) = f->r;
	else if (ft_strnc("hhn", fmt, 3, ' '))
		*va_arg(va, signed char*) = (signed char)f->r;
	else if (ft_strnc("hn", fmt, 2, ' '))
		*va_arg(va, short int*) = (short)f->r;
	else if (ft_strnc("s ", fmt, 2, ' '))
		f->p = va_arg(va, char*);
	else if (ft_strnc("ls S ", fmt, 2, ' '))
		f->p = va_arg(va, wchar_t*);
}

static char	*fmt_arg(t_fmt *f, const char *fmt, char **c, va_list va)
{
	if (ft_strnc("c d i ", fmt, 1, ' '))
		f->i = va_arg(va, int);
	else if (ft_strnc("lld lli ld li D ", fmt, 3, ' '))
		f->i = (fmt[1] == 'l' ? va_arg(va, long long) : va_arg(va, long));
	else if (ft_strnc("hhd hhi hd hi ", fmt, 3, ' '))
		f->i = (fmt[1] == 'h' ? (char)va_arg(va, int) : (short)va_arg(va, int));
	else if (ft_strnc("p o u x X ", fmt, 1, ' '))
		f->u = (fmt[0] == 'p' ? (t_ull)va_arg(va, void*) : va_arg(va, t_u));
	else if (ft_strnc("llo llu llx llX lo lu lx lX O U ", fmt, 3, ' '))
		f->u = (fmt[1] == 'l' ? va_arg(va, t_ull) : va_arg(va, t_ul));
	else if (ft_strnc("hho hhu hhx hhX ho hu hx hX ", fmt, 3, ' '))
		f->u = (fmt[1] == 'h' ? (t_uc)va_arg(va, t_u) : (t_us)va_arg(va, t_u));
	else if (ft_strnc("f F e E g G a A Lf LF Le LE Lg LG La LA ", fmt, 2, ' '))
		f->f = (fmt[1] == 'L' ? va_arg(va, long double) : va_arg(va, double));
	else if (ft_strnc("lc C % ", fmt, 2, ' '))
		f->i = (fmt[0] == '%' ? '%' : va_arg(va, wchar_t));
	else
		fmt_argn(f, fmt, va);
	fmt += ft_strc("lhjztL", *fmt) ? 2 - !ft_strnc("ll hh ", fmt, 2, ' ') : 0;
	return ((*c = (char*)fmt));
}

char		*fmt_parse(t_fmt *f, const char *fmt, char **c, va_list va)
{
	fmt_init(f);
	while (ft_strc("#0- +", *++fmt))
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
	return (fmt_arg(f, fmt, c, va));
}
