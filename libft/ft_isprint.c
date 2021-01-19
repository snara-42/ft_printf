/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:31:20 by snara             #+#    #+#             */
/*   Updated: 2020/11/11 09:49:44 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((' ' <= c && c <= '~') ? 1 : 0);
}

/*
**#include <stdio.h>
**int main(){char s[]="4T \t";
**while(*s)printf("%d",ft_isprint(*s++));return 0;}
*/