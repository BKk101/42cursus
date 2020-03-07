/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:16:32 by bykim             #+#    #+#             */
/*   Updated: 2020/03/07 19:56:39 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int     write_fu(va_list ap, t_format f_info)
{
    char    *str;
    int     len;

    (void)f_info;
    //str = ft_uitoa(va_arg(ap, unsigned int), 0);
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}