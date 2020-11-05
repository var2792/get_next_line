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
	static char	*s[100];
	char		*temp;
	char		w[BUFFER_SIZE + 1];
	int			j;
	int			n;
	//int			t;

	if (fd < 0)
		return (-1);
	temp = NULL;
	if ((n = read(fd, w, BUFFER_SIZE)) > 0)
	{
		j = 0;
		w[n] = '\0';
		//printf("it's\t1\n");
		if (*s != NULL)
		{
			printf("it's\t11\n");
			temp = ft_strjoinsize(*s, w, ft_strsize(w, j));
			free(s);
			j = ft_strsize(w, j);
		}
		//printf("it's\t2\n");
		while (w[ft_strsize(w, j)] != '\0')
		{
			*line = ft_newstr(w, j);
			printf("it's while - %s - %i\n", *line, j);
			j = ft_strsize(w, j) + 1;
			printf("it's end - |%c| %i\n", w[j], j);
			line++;
		}
		//printf("it's\t3 - %s\n", *s);
		*s = ft_newstr(w, j);
		printf("it's\t4 %s\n", *s);
	}
	return ((n == 0) ? 0 : 1);
}
