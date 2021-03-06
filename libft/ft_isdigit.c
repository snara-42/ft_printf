/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:23:05 by snara             #+#    #+#             */
/*   Updated: 2020/11/11 09:49:27 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (('0' <= c && c <= '9') ? 1 : 0);
}

/*
**#include <stdio.h>
**int main(){char s[]="42 ";while(*s)printf("%d",ft_isdigit(*s++));return 0;}
*/
