/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:24:34 by bykim             #+#    #+#             */
/*   Updated: 2020/03/07 22:31:30 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct s_format
{
    int     minus;
    int     plus;
    int     space;
    int     zero;
    int     hash;
    int     width;
    int     precision;
    int     length;
    int     printlen;
    char    *address;
}               t_format;

int     write_fc(va_list ap, t_format f_info);
int     write_fs(va_list ap, t_format f_info);
int     write_fp(va_list ap, t_format f_info);
int     write_fdi(va_list ap, t_format f_info);
int     write_fu(va_list ap, t_format f_info);
int     write_fxX(va_list ap, char c, t_format f_info);
int     write_felse(char c, t_format f_info);

int     ft_strlen(const char *s);
void    *ftt_memset(void *s, int c, size_t n);
int		ft_ischarset(char str, char *charset);
int     ft_atoi(const char *str);
size_t  ft_numlen(int num);
char    *ft_strjoin(char const *s1, char const *s2);
void    ft_multifree(int args, ...);

#endif