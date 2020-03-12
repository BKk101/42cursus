/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:03:41 by bykim             #+#    #+#             */
/*   Updated: 2020/03/12 21:55:54 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 32

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE] = {0};
    int num;

    while()
    {
        num = read(fd, buf, BUFFER_SIZE);
        if (num == 0) //한번에 다 읽은 경우
            ft_strchr(buf, '\n');//\n 올때까지 찾기
        else if(Is_InCharset('\n', buf)) 

        else //여러번 읽는 경우
            continue;
    }
    return (0);
}

int main()
{
    int fd, num;
    char *str1;
    char str[100];

    str[17]=122;
    str[18]=122;
    fd = open("test.txt", O_RDONLY);
    num = read(fd, str, 15);
    num = read(fd, str, 15);
    get_next_line(fd, &str1);
    
}