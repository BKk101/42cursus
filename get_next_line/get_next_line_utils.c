/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:04:53 by bykim             #+#    #+#             */
/*   Updated: 2020/03/12 21:55:57 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		Is_InCharset(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (i + 1);
		i++;
	}
	return (0);
}

char    *ft_strchr(const char *s, int c)
{
    char *ptr;

    ptr = (char *)s;
    while (*ptr)
    {
        if (*ptr == (unsigned char)c)
            return (ptr);
        ptr++;
    }
    if (c == 0)
        return (ptr);
    return (0);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t len;

	len = 0;
	while (src[len])
		len++;
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		size--;
	}
	if (size != 0)
		*dest = '\0';
	return (len);
}