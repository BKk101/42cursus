/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_pcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:09:10 by bykim             #+#    #+#             */
/*   Updated: 2020/03/05 23:15:06 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char    g_hex[] = "0123456789abcdef";

static int     write_hex(long long memory, int len)
{
	unsigned char temp;

	if (memory == 0)
    {
        write(1, "0x", 2);
        return (len + 2);
    }
	temp = g_hex[memory % 16];
	memory /= 16;
	len = write_hex(memory, len + 1);
	write(1, &temp, 1);
    return (len);
}

int     write_fp(va_list ap, t_format f_info)
{
    char    *temp;
    
    temp = va_arg(ap, char *);
    return (write_hex((long long)temp, 0));
}

int     write_fc(va_list ap, t_format f_info)
{
    char temp;

    temp = va_arg(ap, int);
    write(1, &temp, sizeof(char));
    return (1);
}

int     write_fs(va_list ap, t_format f_info)
{
    char    *temp;
    int     len;
    
    temp = va_arg(ap, char *);
    len = ft_strlen(temp);
    write(1, temp, len);
    return (len);
}