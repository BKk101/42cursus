/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:22 by bykim             #+#    #+#             */
/*   Updated: 2020/03/01 17:59:59 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list *res;

    res = lst;
    while (lst)
    {
        res = lst;
        lst = lst->next;
    }
    return (res);
}