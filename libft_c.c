/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:30:51 by snara             #+#    #+#             */
/*   Updated: 2021/01/19 23:51:12 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (c && *s == (char)c)
			return ((char *)s);
		else if (*s == '\0')
			return (NULL);
		s++;
	}
	return (NULL);
}

char	*ft_strnc(const char *str, const char *find, size_t n, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str && find)
	{
		j = 0;
		while (str[i] && str[i] == c)
			i++;
		while (find[j] && str[i + j] && str[i + j] == find[j]
				&& str[i + j] != c && j < n)
			j++;
		if (str[i + j] == c)
			return ((char *)&str[i]);
		else if (!str[i])
			return (NULL);
		while (str[i] && str[i] != c)
			i++;
	}
	return (NULL);
}

int		ft_putcn(const char c, int n, int fd)
{
	int	r;

	r = 0;
	while (0 < n--)
		r += write(fd, &c, 1);
	return (r);
}

int		ft_putsn(const char *s, int n, int fd)
{
	int	i;

	i = 0;
	while (s && (i < n || n < 0) && s[i])
		i++;
	return (fd >= 0 && s ? write(fd, s, i) : i);
}

int		ft_putsc(const char *s, const char c, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] != c && s[i])
		i++;
	return (fd >= 0 && s ? write(fd, s, i) : i);
}
