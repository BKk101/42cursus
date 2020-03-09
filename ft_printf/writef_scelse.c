/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_xXelse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:58:32 by bykim             #+#    #+#             */
/*   Updated: 2020/03/09 18:07:45 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


int         write_felse(char c, t_format f_info) //리턴값 플래그 설정(자리수) + 1
{
    (void)f_info;
    write(1, &c, 1);
    return (1);
}

int     write_fc(va_list ap, t_format f_info)
{
    char temp;

    (void)f_info;
    temp = va_arg(ap, int);
    write(1, &temp, sizeof(char));
    return (1);
}

int     write_fs(va_list ap, t_format f_info)
{
    char    *temp;
    int     len;
    
    (void)f_info;
    temp = va_arg(ap, char *);
    len = ft_strlen(temp);
    write(1, temp, len);
    return (len);
}