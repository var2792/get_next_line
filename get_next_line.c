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

int get_next_line(int fd, char **line)
{
	static char	*s[255];
	int			n;
	int			j;
	//int			t;
	
	n  = 0;
	if (fd < 0)
		return (-1);
	j = 0;
	if (*s != NULL)
		while ((*s)[j] != '\n' && (*s)[j] != '\0')
		{
			j++;
		}
	if (*s == NULL)
		unite_stnext(s, line, fd, &n);
	else
	{
		if ((*s)[j] == '\n')
			divide_static(s, line, j, &n);
		else
		{
			printf("Second!\n");
			if ((*s)[j] == '\0')
				unite_stnext(s, line, fd, &n);
		}
	}
	printf("TEMP - |%s| |%s| %i<-----------------\n", *line, *s, n);
	printf("End get next line!\n");
	
	return ((n == 0) ? 0 : 1);
}

