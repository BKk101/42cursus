/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/03/07 23:40:20 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char        *ft_itoa(int n)
{
    long long   temp;
    size_t      len;
    char        *res;

    len = 1;
    temp = n;
    if (n < 0)
        temp *= -1;
    while ((temp /= 10) > 0)
        len++;
    if ((res = (char *)malloc(len + 1)) == 0)
        return (0);
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

static char        *ft_uitoa(unsigned int n, char c)
{
    long long   temp;
    size_t      len;
    char        *res;

    len= 1;
    temp = n;
    if (c)
        len++;
    while ((temp /= 10) > 0)
        len++;
    if ((res = (char *)malloc(len + 1)) == 0)
        return (0);
    if (c)
        res[0] = c;
    temp = (long long)n * 10;
    res[len] = '\0';
    while ((temp /= 10) > 0)
        res[--len] = temp % 10 + '0';
    if (n == 0)
        res[--len] = '0';
    return (res);
}
/*
int     write_fdi(va_list ap, t_format f_info)
{
    char *str1;
    char *str2;
    char *str3;
    int num;
    int size;
    
    num = va_arg(ap, int); //+, space 처리
    if (num < 0)
        str1 = ft_itoa(num);
    else if (num > 0 && f_info.plus > 0)
        str1 = ft_uitoa(num, '+');
    else if (num > 0 && f_info.space > 0)
        str1 = ft_uitoa(num, ' ');
    else
        str1 = ft_uitoa(num, 0);
    
    size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1)); //size 처리
    
    str2 = (char *)malloc(size - ft_strlen(str1));// 합치기
    if (f_info.minus > 0 && f_info.width > ft_strlen(str1))
    {
        memset(str2, ' ', (size - ft_strlen(str1)));
        str3 = ft_strjoin(str1, str2);
    }
    else if (f_info.width > ft_strlen(str1))
    {
        num = (f_info.zero > 0 ? '0' : ' ');
        memset(str2, num, (size - ft_strlen(str1)));
        str3 = ft_strjoin(str2, str1);
    }
    else
        str3 = ft_strjoin(str1, "");
    write(1, str3, size);
    ft_multifree(3, str1, str2, str3);
    return (size);
}
*/
int     write_fdi(va_list ap, t_format f_info)
{
    char *str1;
    char *str2;
    char *str3;
    int num;
    int size;
    
    num = va_arg(ap, int);
    str1 = ft_itoa(num);
    if (f_info.precision > ft_strlen(str1)) //precision 처리
    {
        str2 = (char *)malloc(f_info.precision - ft_strlen(str1) + 1);
        int a = ft_strlen(str1);
        ftt_memset(str2, '0' , f_info.precision - a + 1);
        str3 = ft_strjoin(str2, str1);
        ft_multifree(2, str1, str2);
    }

    if (num < 0)  // +, space, 음수 처리
        str1 = ft_strjoin("-", str3);
    else if (num > 0 && f_info.plus > 0)
        str1 = ft_strjoin("+", str3);
    else if (num > 0 && f_info.space > 0)
        str1 = ft_strjoin(" ", str3);
    else
        str1 = ft_strjoin(str3, "");
    free(str3);

    size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1)); //size 처리
    
    str2 = (char *)malloc(size - ft_strlen(str1) + 1);// -, 0, width 처리
    if (f_info.minus > 0 && f_info.width > ft_strlen(str1))
    {
        ftt_memset(str2, ' ', size - ft_strlen(str1) + 1);
        str3 = ft_strjoin(str1, str2);
    }
    else if (f_info.width > ft_strlen(str1))
    {
        num = (f_info.zero > 0 ? '0' : ' ');
        ftt_memset(str2, num, size - ft_strlen(str1) + 1);
        str3 = ft_strjoin(str2, str1);
    }
    else
        str3 = ft_strjoin(str1, "");
    write(1, str3, size);//수정
    ft_multifree(3, str1, str2, str3);
    return (size);
}