/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 01:43:38 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 02:56:17 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_c(t_fmt *f, const char *fmt, int fd)
{
	f->l = 1;
	if (*fmt == 's' || *fmt == 'S')
		f->l = ft_putsn(f->p ? f->p : "(null)", f->prec, -1);
	f->r += ft_putcn("0 "[!(f->flag & FLAG('0'))],
			(f->flag & FLAG('-') ? 0 : f->width - f->l), fd);
	if (!(*fmt == 's' || *fmt == 'S'))
		f->r += write(fd, &f->i, 1);
	else
		f->r += ft_putsn(f->p ? f->p : "(null)", f->prec, fd);
	f->r += ft_putcn(' ', f->flag & FLAG('-') ? f->width - f->l : 0, fd);
	return (f->r);
}

static int	ft_printf_i(t_fmt *f, const char *fmt, int fd)
{
	f->l = ft_prefl(fmt, f) + ft_nlen(f->i, BASE(*fmt), f->prec);
	f->t += ft_putcn(' ', !(f->flag & FLAG('0') && f->prec < 0)
			&& !(f->flag & FLAG('-')) ? f->width - f->l : 0, fd);
	f->t += write(fd, PREFX(*fmt), ft_prefl(fmt, f));
	f->t += ft_putcn('0', (f->flag & FLAG('0')
			&& !(f->flag & FLAG('-')) && f->prec < 0) ?
			f->width - f->l : f->prec - ft_nlen(f->i, 10, 1), fd);
	f->t += f->i || f->prec ? ft_putnbr_base(f->i, "0123456789", fd) : 0;
	f->t += ft_putcn(' ', !!(f->flag & FLAG('-')) * (f->width - f->t), fd);
	f->r += f->t;
	return (f->r);
}

static int	ft_printf_u(t_fmt *f, const char *fmt, int fd)
{
	f->l = ft_prefl(fmt, f) + ft_nlenu(f->u, BASE(*fmt), f->prec);
	f->t += ft_putcn(' ', !(f->flag & FLAG('0') && f->prec < 0)
			&& !(f->flag & FLAG('-')) ? f->width - f->l : 0, fd);
	f->t += write(fd, PREFX(*fmt), ft_prefl(fmt, f));
	f->t += ft_putcn('0', (f->flag & FLAG('0')
			&& !(f->flag & FLAG('-')) && f->prec < 0 ?
			f->width - f->l : f->prec - ft_nlenu(f->u, BASE(*fmt), 1)), fd);
	f->t += f->u || f->prec ? ft_putnbr_baseu(f->u, DIGIT(*fmt), fd) : 0;
	f->t += ft_putcn(' ', !!(f->flag & FLAG('-')) * (f->width - f->t), fd);
	f->r += f->t;
	return (f->r);
}

static int	ft_printf_f(t_fmt *f, const char *fmt, int fd)
{
	return (f->r + 0 * *fmt * fd);
}

int			fmt_print(t_fmt *f, const char *fmt, int fd)
{
	if (ft_strc("%cCsS", *fmt))
		ft_printf_c(f, fmt, fd);
	else if (ft_strc("idD", *fmt))
		ft_printf_i(f, fmt, fd);
	else if (ft_strc("poOuUxX", *fmt))
		ft_printf_u(f, fmt, fd);
	else if (ft_strc("fFeEgGaA", *fmt))
		ft_printf_f(f, fmt, fd);
	else if (*fmt != 'n')
		f->r += write(fd, fmt, 1);
	return (f->r);
}
