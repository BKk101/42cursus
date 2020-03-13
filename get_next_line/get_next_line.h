/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:01:54 by bykim             #+#    #+#             */
/*   Updated: 2020/03/12 21:54:45 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int get_next_line(int fd, char **line);
int		Is_InCharset(char str, char *charset);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);

#endif