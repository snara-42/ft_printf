/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:04 by snara             #+#    #+#             */
/*   Updated: 2021/01/21 04:37:20 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# include <float.h>

# define F_INT 309
# define F_FRAC 1075
# define ABS(x) (((x) < 0) ? (-(x)) : (x))
# define MAX(x, y) (((x) < (y)) ? (y) : (x))
# define MIN(x, y) (((x) > (y)) ? (y) : (x))
# define FPLUS(c) (((c) == '+') ? 1 : 0)
# define FMINUS(c) (((c) == '-') ? 2 : 0)
# define FHASH(c) (((c) == '#') ? 4 : 0)
# define FSPACE(c) (((c) == ' ') ? 8 : 0)
# define FZERO(c) (((c) == '0') ? 16 : 0)
# define FLAG(c) (FHASH(c) | FZERO(c) | FMINUS(c) | FSPACE(c) | FPLUS(c))

# define BASE(c) (BASE1(c) ? 10 : BASEX(c))
# define BASE1(c) (c == 'f' || c == 'F' || c == 'e' || c == 'E' || BASE2(c))
# define BASE2(c) (c == 'g' || c == 'G' || c == 'u' || c == 'U' || BASE3(c))
# define BASE3(c) (c == 'd' || c == 'D' || c == 'i')
# define BASEX(c) ((BASE16(c)) ? 16 : BASE8(c))
# define BASE16(c) (c == 'x' || c == 'X' || c == 'p' || c == 'a' || c == 'A')
# define BASE8(c) (((c) == 'o' || (c) == 'O') ? 8 : 10)

# define DIGIT(c) ((BASE(c) == 10) ? "0123456789" : DIG8(c))
# define DIG8(c) ((BASE(c) == 8) ? "01234567" : DIGX(c == 'X' || c == 'A'))
# define DIGX(c) ((c) ? "0123456789ABCDEF" : "0123456789abcdef")
# define PREFX(c) ((BASE(c) == 8 || BASE(c) == 16) ? PREFXU(c) : PREFXS(c))
# define PREFXU(c) (((c) == 'x' || (c) == 'p') ? "0x" : PREFXUU(c))
# define PREFXUU(c) (((c) == 'X') ? "0X" : "0")
# define PREFXS(c) (&"-+ "[!(f->i < 0) * (1 + !(f->flag & FLAG('+')))])

typedef unsigned long long	t_ull;
typedef unsigned long		t_ul;
typedef unsigned int		t_u;
typedef unsigned short		t_us;
typedef unsigned char		t_uc;
typedef uintmax_t			t_um;
typedef long long			t_ll;
typedef long double			t_ld;
typedef struct
{
	uint8_t		flag;
	int			width;
	int			prec;
	int			length;
	long		r;
	int			l;
	int			t;
	t_ll		i;
	t_ull		u;
	t_ld		f;
	char		a[F_INT + F_FRAC + 2];
	void		*p;
}	t_fmt;

int				ft_printf(const char *fmt, ...);
int				ft_vdprintf(int fd, const char *fmt, va_list va);
char			*fmt_parse(t_fmt *f, const char *fmt, char **c, va_list va);
char			*fmt_arg(t_fmt *f, const char *fmt, char **c, va_list va);
int				fmt_print(t_fmt *f, const char *fmt, int fd);
int				ft_prefl(const char *fmt, t_fmt *f);
int				ft_nlenl(long long n, int b, int l);
int				ft_nlenu(unsigned long long n, unsigned int b, int l);
int				ft_putnbr_base(long long n, const char *base, int fd);
int				ft_putnbr_baseu(unsigned long long n, const char*base, int fd);
int				ft_putcn(const char c, int n, int fd);
int				ft_putsn(const char *s, int n, int fd);
int				ft_putsc(const char *s, const char c, int fd);
char			*ft_strc(const char *s, int c);
char			*ft_strnc(const char*str, const char*find, size_t s, char c);
int				ft_flen(long double n, int b, int l);

#endif
