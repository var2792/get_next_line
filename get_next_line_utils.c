/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:55:19 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/05 13:55:28 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strsize(const char *str, int start, int fl0)
{
	unsigned long i;

	i = start;
	while (str[i] != '\0' && str[i] != '\n' && fl0)
		i++;
	while (str[i] != '\0' && !fl0)
		i++;
	return (i);
}

char	*ft_strjoinsize(char const *s1, char const *s2, int size)
{
	int		i;
	int		j;
	char	*res;

	if (!(res = malloc(sizeof(char) * (ft_strsize(s1, 0, 1) + size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (j < size)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_newstr(char *s1, int start, int fl, int fl0)
{
	char	*buff;
	int		num;
	int		i;

	num = ft_strsize(s1, start, fl0);
	if (!(buff = malloc(sizeof(char) * (num + 1))))
		return (NULL);
	i = 0;
	while (i + start < num)
	{
		*(buff + i) = *(s1 + i + start);
		i++;
	}
	if (!fl && *(s1 + i + start) == '\n')
		*(buff + i) = '\n';
	else
		*(buff + i) = '\0';
	return (buff);
}

void	divide_static(char **s, char **line, int end, int *n)
{
	char		*temp;

	*n = 1;
	temp = NULL;
	printf("Here devide!\n");
	*line = ft_newstr(*s, 0, 1, 1);
	temp = ft_newstr(*s, end + 1, 0, 1);
	free(*s);
	*s = temp;
	printf("it's devide end - |%s| - |%s|\n", *line, *s);
	
}

void	unite_stnext(char **s, char **line, int fd, int *n)
{
	char	*buff;
	int		j;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	free(*s);
	printf("Here unite!\n");
	j = 0;
	if (*s != NULL)
	{
		while ((*s)[j] != '\0')
			j++;
		//temp = ft_strjoinsize(*s, buff, ft_strsize(buff, j));
	}
	if ((*n = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[*n] = '\0';
		printf("Here with s!\n");
		*line = ft_newstr(buff, j, 1, 1);
		j = ft_strsize(buff, j, 1) + 1;
		if (buff[j - 1] != '\0')
		{
			*s = ft_newstr(buff, j, 0, 0);
			printf("it's continue |%s| %s\n", *line, *s);
		}
	}
	/*else if (*s != NULL)
	{
		printf("Here without!\t %s\n", *s);
		if (**s != '\0')
			*line = ft_newstr(*s, 0, 1, 0);
		free(*s);
		printf("it's\tnext |%s| - |%s|\n", *line, *s);
	}*/
	free(buff);
}
