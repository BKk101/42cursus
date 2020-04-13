/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:56:22 by bykim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/04/13 19:47:42 by bykim            ###   ########.fr       */
=======
/*   Updated: 2020/04/13 22:15:56 by bykim            ###   ########.fr       */
>>>>>>> 621995f617f190f71ad2fe7abe651c97f2212685
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(nmemb * size)))
		return (0);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
<<<<<<< HEAD
}
=======
}
>>>>>>> 621995f617f190f71ad2fe7abe651c97f2212685
