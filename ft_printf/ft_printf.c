/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 21:25:44 by bykim             #+#    #+#             */
/*   Updated: 2020/03/06 15:54:50 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char g_synf[] = "-+ 0#.*123456789hl";

static int classify_f(char c, va_list ap, t_format f_info)
{
    if (c == '\0')
        return (-1);
    else if (c == 'c')
        return (write_fc(ap, f_info));
    else if (c == 's')
        return (write_fs(ap, f_info)); 
    else if (c == 'p')
        return (write_fp(ap, f_info)); 
    else if (c == 'd' || c =='i')
        return (write_fdi(ap, f_info)); 
    else if (c == 'u')
        return (write_fu(ap, f_info));
    else if (c == 'x' || c == 'X')
        return (write_fxX(ap, c, f_info)); 
    else
        return (write_felse(c, f_info));
}

static t_format check_f(const char *arg, va_list ap, t_format f_info)
{
    ft_memset(&f_info, -1, sizeof(t_format));
    while (ft_ischarset(*arg, g_synf))
    {
        if (*arg >= '1' && *arg <= '9')
        {
            f_info.width = ft_atoi(arg);
            arg += ft_numlen(f_info.width);
            continue ;
        }
        else if (*arg == '.')
        {
            f_info.precision = ft_atoi(++arg);
            arg += ft_numlen(f_info.precision);
            continue ;
        }
        else if (*arg == '-')
            f_info.minus = 1;
        else if (*arg == '+')
            f_info.plus = 1;
        else if (*arg == ' ')
            f_info.space = 1;
        else if (*arg == '0')
            f_info.zero = 1;
        arg++;
    }
    if ((f_info.printlen = classify_f(*arg, ap, f_info)) == -1)
        f_info.address = (char *)arg;
    else
        f_info.address = (char *)arg + 1;
    return (f_info);
}

int ft_printf(const char * format, ...)
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
            f_info = check_f(++format, ap, f_info);
            format = f_info.address;
            if (f_info.printlen == -1)
                continue;
            len += f_info.printlen;
        }
        else
        {
            write(1, format, 1);
            len++;
            format++;
        }
    }
    va_end(ap);
    return (len);    
}

int main()
{
    int num;
    //char s[]="applepie";

    num = ft_printf("%+8d", 1234);
    printf("%d", num);
    //num = ft_printf("%d\n%i\n%u\n%p\n%s\n%c\n%x\n%X\n", 32, 23, -10, s, s, 'Z', 1328, 1328);
    //printf("%d\n\n", num);
    //num = printf("%d\n%i\n%u\n%p\n%s\n%c\n%x\n%X\n", 32, 23, -10, s, s, 'Z', 1328, 1328);
    //printf("%d\n\n", num);
}

//에러
//%c 하고 뒤에 인자 안들어 온 경우
//널문자 입력
//정의되지 않은 %* 사용
//%c 하고 형식에 안맞는 입력 (%c, "123")