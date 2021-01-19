/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:56:23 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 03:19:03 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARG FMT,INT_MIN,INT_MAX,15,'a',63,-13,12,INT_MIN,"",'%'
#define FMT "%s|%d|%i|hello, world|%12.5x|%-4.3X|%06.3o|%*.*u|%-15.p|%c|\n"

int	main(void)
{
	ft_printf("%#");
	printf("printf   : %d\n", printf(FMT, ARG));
	ft_printf("ft_printf: %d\n", ft_printf(FMT, ARG));
	return (0);
}
