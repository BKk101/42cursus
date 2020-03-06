/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/03/06 18:41:41 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char        *ft_itoa(int n)
{
    long long   temp;
    size_t      len;
    char        *res;

    temp = n;
    if (n < 0)
        temp *= -1;
    if ((len = 1) == 1 && n < 0)
        len++;
    while ((temp /= 10) > 0)
        len++;
    if ((res = (char *)malloc(len + 1)) == 0)
        return (0);
    if (n < 0)
        res[0] = '-';
    if (n == 0)
        res[0] = '0';
    temp = (long long)n * 10;
    if (n < 0)
        temp *= -1;
    res[len] = '\0';
    while ((temp /= 10) > 0)
        res[--len] = temp % 10 + '0';
    return (res);
}

static char        *ft_uitoa(unsigned int n)
{
    long long   temp;
    size_t      len;
    char        *res;

    len= 1;
    temp = n;
    while ((temp /= 10) > 0)
        len++;
    if ((res = (char *)malloc(len + 1)) == 0)
        return (0);
    if (n == 0)
        res[0] = '0';
    temp = (long long)n * 10;
    res[len] = '\0';
    while ((temp /= 10) > 0)
        res[--len] = temp % 10 + '0';
    return (res);
}
/*
int     write_fdi(va_list ap, t_format f_info)
{
    char    *str;
    int     len;

    str = ft_itoa(va_arg(ap, int));
    len = ft_strlen(str);
    if (f_info.width <= len)
        write(1, str, len);
    else
        write(1,str, len);
    free(str);
    return (len);
}
*/
int     write_fdi(va_list ap, t_format f_info)
{
    char *str1;
    char *str2;
    char *str3;
    int num;
    int size;

    if (f_info.plus > 0 && f_info.space > 0)
        f_info.space = 0;
    if (f_info.minus > 0 && f_info.zero > 0)
        f_info.zero = 0; //f_info 전처리 따로 뺴도 될듯
    
    num = va_arg(ap, int);
    str1 = ft_itoa(num);
    if (f_info.width <= f_info.precision)
        size = f_info.precision;
    else
        size = f_info.width;
    if (size < ft_strlen(str1))
        size = ft_strlen(str1);

    if (f_info.space > 0 && num >= 0) //uitoa에서 처리
        str2 = ft_strjoin(" ", str1);
    else if (f_info.plus > 0 && num >= 0)
        str2 = ft_strjoin("+", str1);
    free(str1);
    
    if (f_info.zero > 0 && f_info.width > ft_strlen(str2))
    {
        str1 = (char *)malloc(size - ft_strlen(str2));
        memset(str1, '0', (size - ft_strlen(str2)));
        str3 = ft_strjoin(str1, str2);
    }
    else if (f_info.minus > 0 && f_info.width > ft_strlen(str2))
    {
        str1 = (char *)malloc(size - ft_strlen(str2));
        memset(str1, ' ', (size - ft_strlen(str2)));
        str3 = ft_strjoin(str2, str1);
    }//width만있는경우
    else if (f_info.width > ft_strlen(str2))
    {
        str1 = (char *)malloc(size - ft_strlen(str2));
        memset(str1, ' ', (size - ft_strlen(str2)));
        str3 = ft_strjoin(str1, str2);
    }
    else
        str3 = str2;
    write(1, str3, size);
    free(str2);
    free(str1);
    free(str3);
    return (size);
}

int     write_fu(va_list ap, t_format f_info)
{
    char    *str;
    int     len;

    (void)f_info;
    str = ft_uitoa(va_arg(ap, unsigned int));
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}