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

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*join_temp(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	//printf("==> %li %li\n", len_s1, len_s2);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		res[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int		ft_findchr(char *st, char c)
{
	int		i;

	i = 0;
	if (!st)
		return (-1);
	while (c != st[i])
	{
		if (st[i] == '\0')
			break ;
		i++;
	}
	if (st[i] == '\0')
		return (-1);
	return (i);
}

void	divide_static(char **st)
{
	char	*temp;
	int		i;
	int		j;
	int		len_temp;

	i = 0;
	j = 0;
	if (!(**st))
		return ;
	while ((*st)[i] && (*st)[i] != '\n')
		i++;
	len_temp = (ft_strlen(*st) - i) + 1;
	//printf("Here devide!\n");
	if (!(temp = malloc(sizeof(char) * len_temp)))
	{
		free(*st);
		return ;
	}
	i++;
	while ((*st)[i])
		temp[j++] = (*st)[i++];
	temp[j] = '\0';
	free(*st);
	*st = temp;
}

void	unite_stnext(char **line, char **st)
{
	int		i;

	i = 0;
	//printf("Here unite!\n");
	if (!(*st))
		return ;
	while ((*st)[i] && (*st)[i] != '\n')
		i++;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
	{
		free(*st);
		return ;
	}
	i = 0;
	while ((*st)[i] && (*st)[i] != '\n')
	{
		(*line)[i] = (*st)[i];
		i++;
	}
	(*line)[i] = '\0';
	//*st = NULL;
	//free(*st);
	//
}
