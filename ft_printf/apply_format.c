/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:14:06 by bykim             #+#    #+#             */
/*   Updated: 2020/03/08 15:21:40 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *apply_precision(char *str1, t_format f_info)
{
    char *str2;
    char *str3;

    str2 = (char *)malloc(f_info.precision - ft_strlen(str1) + 1);
    ftt_memset(str2, '0' , f_info.precision - ft_strlen(str1) + 1);
    str3 = ft_strjoin(str2, str1);
    ft_multifree(2, str1, str2);
    return (str3);
}