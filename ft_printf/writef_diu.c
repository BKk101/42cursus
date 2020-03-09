/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/03/09 18:04:12 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int     write_fdi(va_list ap, t_format f_info)
{
    char    *str1;
    char    *str2;
    int     num;
    int     size;
    
    num = va_arg(ap, int);
    str1 = apply_precision(ftt_itoa(num), f_info); //precision 처리
    str2 = apply_plus_space_negative(num, str1, f_info);  // +, space, 음수 처리
    size = (f_info.width > ft_strlen(str2) ? f_info.width : ft_strlen(str2)); //size 처리
    str1 = apply_minus_zero_width(size, str2, f_info); // -, 0, width 처리
    write(1, str1, size);
    free(str1);
    return (size);
}

int     write_fu(va_list ap, t_format f_info)
{
    char            *str1;
    char            *str2;
    unsigned int    num;
    int             size;
    
    num = va_arg(ap, int);
    str1 = apply_precision(ftt_uitoa(num), f_info); //precision 처리
    size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1)); //size 처리
    str2 = apply_minus_zero_width(size, str1, f_info); // -, 0, width 처리
    write(1, str2, size);
    free(str2);
    return (size);
}