/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_xXelse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:58:32 by bykim             #+#    #+#             */
/*   Updated: 2020/03/06 18:24:19 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char g_hex_low[] = "0123456789abcdef";
static char g_hex_up[] = "0123456789ABCDEF";

static int  write_hex(char c, unsigned int num, int len)
{
	unsigned char temp;

	if (num == 0)
        return (len);
    if (c == 'x')
	    temp = g_hex_low[num % 16];
    if (c == 'X')
        temp = g_hex_up[num % 16];
    num /= 16;
	len = write_hex(c, num, len + 1);
	write(1, &temp, 1);
    return (len);
}

int         write_fxX(va_list ap, char c, t_format f_info)
{
    unsigned int temp;
    
    (void)f_info;
    temp = va_arg(ap, unsigned int);
    return (write_hex(c, temp, 0));
}

int         write_felse(char c, t_format f_info) //리턴값 플래그 설정(자리수) + 1
{
    (void)f_info;
    write(1, &c, 1);
    return (1);
}