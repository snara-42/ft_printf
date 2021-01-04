/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:04 by snara             #+#    #+#             */
/*   Updated: 2021/01/04 21:07:53 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include "libft/libft.h"
# define ABS(x) (((x) < 0) ? (-(x)) : (x))
# define FHASH(c) (((c) == '#') ? (1 << 0) : 0)
# define FZERO(c) (((c) == '0') ? (1 << 1) : 0)
# define FMINUS(c) (((c) == '-') ? (1 << 2) : 0)
# define FSPACE(c) (((c) == ' ') ? (1 << 3) : 0)
# define FPLUS(c) (((c) == '+') ? (1 << 4) : 0)
# define FAPOS(c) (((c) == '\'') ? (1 << 5) : 0)
# define FLAG(c) (FHASH(c) | FZERO(c) | FMINUS(c) | FSPACE(c) | FPLUS(c))

typedef struct	s_fmt
{
	uint8_t		flag;
	int			width;
	int			prec;
	int			length;
	int			r;
	int			l;
	long long	i;
	t_ull		u;
	t_ull		tmp;
	void		*p;
}				t_fmt;

int				ft_vfprintf(int fd, const char *fmt, va_list va);
int				ft_printf(const char *fmt, ...);

#endif
