/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 02:42:06 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(int fd, const char *fmt, va_list va)
{
	t_fmt	f;

	f.r = 0;
	while (fmt && *fmt != '\0')
	{
		f.r += ft_putsc(fmt, '%', fd);
		if (*(fmt += ft_putsc(fmt, '%', -1)) == '%')
		{
			fmt_parse(&f, fmt, (char**)&fmt, va);
			fmt_print(&f, fmt, fd);
			fmt++;
		}
	}
	return (f.r);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	va;
	int		r;

	va_start(va, fmt);
	r = ft_vdprintf(1, fmt, va);
	va_end(va);
	return (r);
}
