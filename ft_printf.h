/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:04 by snara             #+#    #+#             */
/*   Updated: 2021/01/10 01:11:12 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# define ABS(x) (((x) < 0) ? (-(x)) : (x))
# define MAX(x, y) (((x) < (y)) ? (y) : (x))
# define MIN(x, y) (((x) > (y)) ? (y) : (x))
# define FZERO(c) (((c) == '0') ? 1 : 0)
# define FMINUS(c) (((c) == '-') ? 2 : 0)
# define FHASH(c) (((c) == '#') ? 4 : 0)
# define FSPACE(c) (((c) == ' ') ? 8 : 0)
# define FPLUS(c) (((c) == '+') ? 16 : 0)
# define FLAG(c) (FHASH(c) | FZERO(c) | FMINUS(c) | FSPACE(c) | FPLUS(c))

typedef unsigned long long	t_ull;
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
	double		f;
	t_ull		t;
	void		*p;
}				t_fmt;

int				ft_printf(const char *fmt, ...);
int				ft_vfprintf(int fd, const char *fmt, va_list va);
int				ft_nlen(int n, int b, int l);
int				ft_nlenu(unsigned int n, unsigned int b, int l);
int				ft_putnbr_base(long long n, const char *base, int fd);
int				ft_putnbr_baseu(t_ull n, const char *base, int fd);
int				ft_strnlen(const char *s, int n);
int				ft_putcharn(char c, int n, int fd);
int				ft_putstrn(char *s, int n, int fd);
char			*ft_strchr(const char *s, int c);

#endif
