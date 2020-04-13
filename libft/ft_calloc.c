/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:56:22 by bykim             #+#    #+#             */
/*   Updated: 2020/04/13 23:24:56 by bykim            ###   ########.fr       */
/*   Updated: 2020/04/13 22:15:56 by bykim            ###   ########.fr       */
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
}
