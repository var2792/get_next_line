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

int		ft_strsize(const char *str, int start)
{
	unsigned long i;

	i = start;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoinsize(char const *s1, char const *s2, int size)
{
	int		i;
	int		j;
	char	*res;

	//if (!s1 || !s2)
		//return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strsize(s1, 0) + size + 1))))
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

char	*ft_newstr(char *s1, int start)
{
	char	*buff;
	int		num;
	int		i;

	if ((num = ft_strsize(s1, start)) >= BUFFER_SIZE)
	{
		//printf("it's\t31 = %i\n", ft_strsize(s, start));
		return (NULL);
	}
	if (!(buff = malloc(sizeof(char) * (num + 1))))
		return (NULL);
	i = 0;
	while (i + start < num)
	{
		*(buff + i) = *(s1 + i + start);
		i++;
	}
	//printf("============>%i %c\t", i + start, *(s1 + i + start));
	*(buff + i) = '\0';
	return (buff);
}
