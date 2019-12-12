/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:24:09 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 16:24:24 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

char	*ft_fill_str(t_part *init, char *str)
{
	size_t	len;
	int		i;
	t_part	*save;

	i = 0;
	while (init != NULL)
	{
		len = init->len;
		while (len > 0)
		{
			str[i] = init->str[i % BUFF];
			len--;
			i++;
		}
		save = init;
		init = init->next;
		free(save);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_make_str(t_part *init)
{
	size_t	strlenmax;
	t_part	*save;
	char	*str;

	strlenmax = 0;
	save = init;
	while (save != NULL)
	{
		strlenmax += save->len;
		save = save->next;
	}
	if (!(str = (char *)malloc(sizeof(char) * (strlenmax + 1))))
		return (NULL);
	return (str);
}

t_part	*ft_file_to_list(int fd)
{
	t_part	*init;
	t_part	*next;
	t_part	*save;

	if (!(init = (t_part *)malloc(sizeof(t_part))))
		return (NULL);
	init->len = read(fd, init->str, BUFF);
	init->next = NULL;
	next = init;
	while (next->len == BUFF)
	{
		save = next;
		if (!(next = (t_part *)malloc(sizeof(t_part))))
			return (NULL);
		save->next = next;
		next->len = read(fd, next->str, BUFF);
		next->next = NULL;
	}
	return (init);
}

char	*ft_readfile(const char *path)
{
	int		fd;
	char	*str;
	t_part	*init;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!(init = ft_file_to_list(fd)))
	{
		free_t_parts(init);
		return (NULL);
	}
	if (!(str = ft_make_str(init)))
	{
		free_t_parts(init);
		return (NULL);
	}
	str = ft_fill_str(init, str);
	return (str);
}
