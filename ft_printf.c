/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2020/12/15 18:53:31 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(int fd, const char *fmt, va_list va)
{
	int		i;
	int		r;
	t_fmt	f;

	i = 0;
	r = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			f.flag = 0;
			f.width = 0;
			f.precision = 1;
			f.length = 0;
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
					f.width += 10 * f.width + fmt[i++] - '0';
				}
			if (fmt[i] == '.')
			{
				if (fmt[++i] == '*')
				{
					i++;
					f.precision = va_arg(va, int);
				}
				else
				{
					f.precision = (fmt[i] == '-') ? -1 : 0;
					while (ft_isdigit(fmt[i]))
					{
						f.precision += 10 * f.precision + fmt[i++] - '0';
					}
				}
			}
			if (fmt[i] == 'h' || fmt[i] == 'l')
			{
				f.length += (fmt[i] == 'h' ?
					-1 - (fmt[i + 1] == 'h') : 1 + (fmt[i + 1] == 'l'));
				i += ABS(f.length);
			}
			if (fmt[i] == 'c' || fmt[i] == '%')
			{
				f.u = (fmt[i] == '%' ? '%' : (unsigned char)va_arg(va, int));
				while (!(f.flag & FMINUS('-')) && 0 < --f.width)
					f.r += write(fd, (f.flag & FZERO('0') ? "0" : " "), 1);
				f.r += write(fd, &f.u, 1);
				while ((f.flag & FMINUS('-')) && 0 < --f.width)
					f.r += write(fd, " ", 1);
			}
			else if (fmt[i] == 'd' || fmt[i] == 'i')
			{
				f.i = va_arg(va, int);
				f.r += ft_putnbr_fd(f.i, fd);
			}
			else if (fmt[i] == 'u')
			{
				f.u = va_arg(va, unsigned int);
				f.r += ft_putnbr_fd(f.u, fd);
			}
			else if (ft_strchr("poxX", fmt[i]))
			{
				if (fmt[i] == 'p')
				{
					f.flag |= FHASH('#');
					f.p = va_arg(va, void*);
					f.u = (uint64_t)f.p;
				}
				else
					f.u = va_arg(va, unsigned int);
				f.r += write(fd, "0x", (f.flag & FHASH('#') ? 1 + !(fmt[i] == 'o') : 0));
				f.r += ft_putnbr_baseu(f.u, "0123456789abcdef", fd);
			}
			else if (fmt[i] == 's')
			{
				f.p = (char*)va_arg(va, const char*);
				f.r += ft_putstr_fd(f.p, fd);
			}
			else if (fmt[i] == 'p')
			{
				f.p = va_arg(va, void*);
				f.r += write(fd, "0x", 2);
				f.r += ft_putnbr_base((long)f.p, "0123456789abcdef", fd);
			}
			else if (fmt[i] == 'n')
			{
				f.p = va_arg(va, int*);
				*(int*)f.p = f.r;
			}
			i++;
		}
		else
			r += write(fd, &fmt[i++], 1);
	}
	return (r);
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
