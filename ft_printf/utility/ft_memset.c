/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:17:03 by bykim             #+#    #+#             */
/*   Updated: 2020/03/04 20:41:26 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *temp;
    unsigned long   idx;

    temp = (unsigned char *)s;
    idx = 0;
    while (idx < n)
        temp[idx++] = (unsigned char)c;
    return (s);
}