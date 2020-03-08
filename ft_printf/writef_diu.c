/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/03/08 15:23:41 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int     write_fdi(va_list ap, t_format f_info)
{
    char *str1;
    char *str2;
    char *str3;
    int num;
    int size;
    
    num = va_arg(ap, int);
    if (f_info.precision > ft_strlen(str1)) //precision 처리
        str3 = apply_precision(ftt_itoa(num), f_info);

    //apply_plus_space    
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
    write(1, str3, size);
    ft_multifree(3, str1, str2, str3);
    return (size);
}