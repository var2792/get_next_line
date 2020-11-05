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
	char		*temp;
	char		w[BUFFER_SIZE + 1];
	int			j;
	//int			t;

	if (fd < 0)
		return (-1);
	temp = NULL;
	j = 0;
	if (*s != NULL)
		while (*s[j] != '\n' || *s[j] != '\0')
			j++;
	if (*s[j] != '\n' || *s[j] != '\0')
		free(*s);
		//*s = temp;
		//free (&temp);
		////printf("it's\t15\n");
		//j = ft_strsize(w, j);
		////printf("it's\t16\n");
		
		//temp = ft_strjoinsize(*s, w, ft_strsize(w, j));
	}
	
	if ((n = read(fd, w, BUFFER_SIZE)) > 0)
	{
		j = 0;
		w[n] = '\0';
		//printf("it's\t1\n");
		*line = ft_newstr(w, j);
		printf("it's while - %s - %i\n", *line, j);
		j = ft_strsize(w, j) + 1;
		printf("it's end - |%c| %i\n", w[j], j);
		if (w[j] != '\0')
			*s = ft_newstr(w, j);
		printf("it's\tnext %s\n", *s);
	}
	return ((n == 0) ? 0 : 1);
}
