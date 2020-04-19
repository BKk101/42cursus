/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:31:37 by bykim             #+#    #+#             */
/*   Updated: 2020/04/19 20:31:39 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_incharset(char str, char const *charset)
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

static char	*make_trim(char *des, char *start, char *end)
{
	int len;

	len = 0;
	while (start < end)
		des[len++] = *(start++);
	des[len] = '\0';
	return (des);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char		*end;
	long long	len;

	while (is_incharset(*s1, set))
		s1++;
	len = 0;
	while (s1[len])
	{
		while (is_incharset(s1[len], set) == 0 && s1[len] != '\0')
			len++;
		end = (char *)&s1[len];
		if (s1[len] == '\0')
			break ;
		while (is_incharset(s1[len], set))
			len++;
	}
	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	if (len == 0)
		res[0] = '\0';
	if (len == 0)
		return (res);
	res = make_trim(res, (char *)s1, end);
	return (res);
}