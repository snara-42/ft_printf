/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:54:45 by snara             #+#    #+#             */
/*   Updated: 2020/12/14 17:26:27 by snara            ###   ########.fr       */
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
		if (fmt[i] == '%' && fmt[++i] != '%')
		{
			f.flag = 0;
			f.width = 0;
			f.precision = 0;
			f.length = 0;
			while (ft_strchr("#0- +", fmt[i]))
			{
				f.flag |= FLAG(fmt[i]);
				i++;
			}
			if (fmt[i] == '*')
			{
				i++;
				f.width = va_arg(va, int);
				f.flag |= (f.width < 0 ? FLAG('-') : 0);
			}
			else
				while (0 <= fmt[i] && fmt[i] <= '9')
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
					while (0 <= fmt[i] && fmt[i] <= '9')
					{
						f.precision += 10 * f.precision + fmt[i++] - '0';
					}
			}
			else
				f.precision = 1;
			if (fmt[i] == 'h' || fmt[i] == 'l')
			{
				f.length += (fmt[i] == 'h' ?
					-1 - (fmt[i + 1] == 'h') : 1 + (fmt[i + 1] == 'l'));
				i += ABS(f.length);
			}
			if (fmt[i] == 'c')
			{
				f.i = va_arg(va, int);
			}
			else if (fmt[i] == 'd' || fmt[i] == 'i')
			{
				f.i = va_arg(va, int);
			}
			else if (ft_strchr("ouxX", fmt[i]))
			{
				f.u = va_arg(va, unsigned int);
			}
			else if (fmt[i] == 's')
			{
				f.p = va_arg(va, char*);
			}
			else if (fmt[i] == 'p')
			{
				f.p = va_arg(va, void*);
			}
			else if (fmt[i] == 'n')
			{
				f.p = va_arg(va, int*);
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
