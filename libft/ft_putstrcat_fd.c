/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcat_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:14:24 by snara             #+#    #+#             */
/*   Updated: 2020/12/04 23:18:30 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrcat_fd(char *s1, char *s2, int fd)
{
	size_t	i;

	i = 0;
	if (!s1)
		return ;
	while (s1[i])
		i++;
	write(fd, s1, i);
	i = 0;
	if (!s2)
		return ;
	while (s2[i])
		i++;
	write(fd, s2, i);
}
