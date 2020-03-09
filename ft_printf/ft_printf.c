/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 21:25:44 by bykim             #+#    #+#             */
/*   Updated: 2020/03/09 20:25:29 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void init_info(t_format *f_info)
{
    f_info->minus = 0;
	f_info->plus = 0;
	f_info->space = 0;
	f_info->hash = 0;
	f_info->zero = 0;
	f_info->width = 0;
	f_info->precision = -1;
	f_info->length = -1;
	f_info->printlen = 0;
    f_info->address = 0;
}

int         ft_printf(const char * format, ...)
{
    t_format    f_info;
    va_list     ap;
    int         len;

    va_start(ap, format);
    len = 0;
    while (*format)
    {
        if (*format == '%')
        {
            init_info(&f_info);
            f_info = check_format(++format, ap, f_info);
            format = f_info.address;
            if (f_info.printlen == -1)
                continue;
            len += f_info.printlen;
        }
        else
        {
            write(1, format++, 1);
            len++;
        }
    }
    va_end(ap);
    return (len);    
}

int main()
{
    int num;
    char s[]="12345";
    
    num = printf("%*.*s %c\n", 20, 0, s, 'Z');
    printf("%d\n", num);
    fflush(stdout);
    num = ft_printf("%*.*s %c\n", 20, 0, s, 'Z');
    printf("%d\n", num);
    //num = ft_printf("%d\n%i\n%u\n%p\n%s\n%c\n%x\n%X\n", 32, 23, -10, s, s, 'Z', 1328, 1328);
    //printf("%d\n\n", num);
    //num = printf("%d\n%i\n%u\n%p\n%s\n%c\n%x\n%X\n", 32, 23, -10, s, s, 'Z', 1328, 1328);
    //printf("%d\n\n", num);
}