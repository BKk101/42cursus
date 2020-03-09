/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:14:06 by bykim             #+#    #+#             */
/*   Updated: 2020/03/09 16:33:23 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *apply_precision(char *str, t_format f_info)
{
    char *temp;
    char *res;
    int len;

    len = ft_strlen(str); //str은 부호 뗀 숫자, 이걸로 precision과 비교
    temp = (char *)malloc(f_info.precision - len + 1);
    if (f_info.precision > len) 
    {
        ftt_memset(temp, '0' , f_info.precision - len + 1);
        res = ft_strjoin(temp, str);
    }
    else
        res = ft_strjoin(str, "");
    ft_multifree(2, str, temp);
    return (res);
}

char    *apply_plus_space_negative(long long num, char *str, t_format f_info)
{
    char *res;

    if (num < 0)
        res = ft_strjoin("-", str);
    else if (num > 0 && f_info.plus > 0)
        res = ft_strjoin("+", str);
    else if (num > 0 && f_info.space > 0)
        res = ft_strjoin(" ", str);
    else
        res = ft_strjoin(str, "");
    free(str);
    return (res);
}

char    *apply_minus_zero_width(int size, char *str, t_format f_info)
{
    char *temp;
    char *res;
    int len;
    int flag;

    len = ft_strlen(str);
    temp = (char *)malloc(size - len + 1);
    if (f_info.minus > 0 && f_info.width > len) 
    {
        ftt_memset(temp, ' ', size - len + 1);
        res = ft_strjoin(str, temp);
    }
    else if (f_info.width > len) //precision 유무에 따라 0 적용 //s일때 따로
    {
        if (f_info.precision >= 0)
            f_info.zero = 0;
        flag = (f_info.zero > 0 ? '0' : ' ');
        ftt_memset(temp, flag, size - len + 1);
        res = ft_strjoin(temp, str);
    }
    else
        res = ft_strjoin(str, "");
    ft_multifree(2, str, temp);
    return (res);
}