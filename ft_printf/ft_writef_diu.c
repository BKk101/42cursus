/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/03/06 15:37:26 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char        *ft_itoa(int n)
{
    long long   temp;
    size_t      len;
    char        *res;

    len= 1;
    temp = n;
    if (n < 0)
        temp *= -1;
    if (n < 0)
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

int     write_fu(va_list ap, t_format f_info)
{
    char    *str;
    int     len;

    str = ft_uitoa(va_arg(ap, unsigned int));
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}