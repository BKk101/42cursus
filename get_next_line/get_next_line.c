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
    char *start;
	char *end;
	char *temp;
	int num;

    start = buf;
	while(Is_InCharset('\n', start) == 0)//start 대신  buf해도 될듯
    {
        num = read(fd, buf, BUFFER_SIZE);
    	if(Is_InCharset('\n', start)) //한번 읽어서 개행 포함
		{
			end = ft_strchr(start, '\n');
			temp = (char *)malloc(end - start + 1);
			ft_strlcpy(temp, start, end - start + 1);
		}
        else //여러번 읽는 경우
		{    
			buf += BUFFER_SIZE;
			continue;
		}
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