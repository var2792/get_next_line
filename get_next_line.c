/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:55:06 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/05 13:55:10 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*s[255];
	int				n;
	
	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0) //nb = read(fd, NULL, 0) < 0
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (ft_findchr(s[fd], '\n') < 0 && n > 0)
	{
		if ((n = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[n] = '\0';
			//if (ft_findchr(buff, '\0') != n)
			s[fd] = join_temp(s[fd], buff);
			//printf("Here |%s|\n", s[fd]);
		}
		else
		{
			//s[fd] = NULL;
			free(buff);
			if (n == 0)
				return (0);
			return(-1);
		}
	}
	if (s[fd])
	{
		unite_stnext(line, &s[fd]);
		divide_static(&s[fd]);
	}
	//if (*line)
		//printf("TEMP line - |%s|<-----------------\n", *line);
	//if (*s)
		//printf("TEMP static - |%s|<-----------------\n", s);
	//printf("End get next line!\t%i\n", n);
	free(buff);
	return ((n == 0) ? 0 : 1);
}
