/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:56:23 by snara             #+#    #+#             */
/*   Updated: 2021/01/20 02:21:18 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARG FMT,INT_MIN,LONG_MAX,15,L'a',15,2,1,INT_MIN,'%'
#define FMT "%s|%lld|%hhu|hello, world|%#12.x|%010lc|%12.x|%.*u|%#05.o|%#x|\n"

int	main(void)
{
	ft_printf("%#");
	printf("printf   : %d\n", printf(FMT, ARG));
	ft_printf("ft_printf: %d\n", ft_printf(FMT, ARG));
	return (0);
}
