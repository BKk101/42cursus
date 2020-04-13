/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:06:48 by bykim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/04/13 19:57:07 by bykim            ###   ########.fr       */
=======
/*   Updated: 2020/04/13 22:12:43 by bykim            ###   ########.fr       */
>>>>>>> 621995f617f190f71ad2fe7abe651c97f2212685
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	idx;

	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	idx = 0;
	while (idx < len && s[start] != 0)
		res[idx++] = s[start++];
	res[idx] = '\0';
	return (res);
}
