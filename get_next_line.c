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
	char			buff[BUFFER_SIZE + 1];
	static char		*s;
	int				n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (ft_findchr(s, '\n') < 0 && n > 0)
	{
		if ((n = read(fd, buff, BUFFER_SIZE)) >= 0)
		{
			buff[n] = '\0';
			s = join_temp(s, buff);
		}
	}
	if (s)
	{
		unite_stnext(line, &s);
		divide_static(&s);
	}
	printf("TEMP - |%s| |%s| %i<-----------------\n", *line, s, n);
	printf("End get next line!\n");
	return ((n == 0) ? 0 : n);
}
