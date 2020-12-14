/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:04 by snara             #+#    #+#             */
/*   Updated: 2020/12/14 17:25:43 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include "libft.h"
# define ABS(x) (((x) < 0) ? (-x) : (x))
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
	int			precision;
	int8_t		length;
	int			r;
	int64_t		i;
	uint64_t	u;
	void		*p;
}				t_fmt;

int				ft_vfprintf(int fd, const char *fmt, va_list va);
int				ft_printf(const char *fmt, ...);

#endif
