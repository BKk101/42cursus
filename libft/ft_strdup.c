/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:44:28 by bykim             #+#    #+#             */
/*   Updated: 2020/04/13 23:32:39 by bykim            ###   ########.fr       */
/*   Updated: 2020/04/13 22:15:06 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	long long	len;
	char		*ptr;

	len = 0;
	while (src[len])
		len++;
	if ((ptr = (char *)malloc(len + 1)) == 0)
		return (0);
	ptr[len] = 0;
	while (--len >= 0)
		ptr[len] = src[len];
	return (ptr);
}
