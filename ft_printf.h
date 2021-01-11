/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:04 by snara             #+#    #+#             */
/*   Updated: 2021/01/12 04:45:11 by snara            ###   ########.fr       */
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
# define SIGNI(c) ((c) == 'i' || (c) == 'd')
# define SIGNF(c) ((c) == 'e' || (c) == 'f' || (c) == 'g')
# define SIGNED(c) (SIGNI(c) || SIGNF(c))
# define BASE(c) (((c) == 'i' || (c) == 'd' || (c) == 'u') ? 10 : BASEX(c))
# define BASEX(c) (((c) == 'x' || (c) == 'X' || (c) == 'p') ? 16 : BASEO(c))
# define BASEO(c) (((c) == 'o') ? 8 : 10)
# define PREFL(c) ((BASE(c) == 8 || BASE(c) == 16) ? PREFLU(c) : PREFLS(c))
# define PREFLU(c) (((f.flag & FLAG('#') && f.u) || (c) == 'p') * BASE(c) / 8)
# define PREFLS(c) (SIGNED(c) && (f.flag & (FLAG('+') | FLAG(' ')) || f.i < 0))
# define PREFX(c) ((BASE(c) == 8 || BASE(c) == 16) ? PREFXU(c) : PREFXS(c))
# define PREFXU(c) (((c) == 'x' || (c) == 'p') ? "0x" : PREFXUU(c))
# define PREFXUU(c) (((c) == 'X') ? "0X" : "0")
# define PREFXS(c) (&"-+ "[!(f.i < 0) * (1 + !(f.flag & FLAG('+')))])

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;
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
int				ft_nlen(long long n, int b, int l);
int				ft_nlenu(t_ull n, unsigned int b, int l);
int				ft_putnbr_base(long long n, const char *base, int fd);
int				ft_putnbr_baseu(t_ull n, const char *base, int fd);
int				ft_strnlen(const char *s, int n);
int				ft_putcharn(const char c, int n, int fd);
int				ft_putstrn(const char *s, int n, int fd);
char			*ft_strchr(const char *s, int c);

#endif
