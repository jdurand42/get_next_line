/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/21 13:28:41 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char  *parse_test(int fd, char *buffer)
{
	int ret;
	char *str;

	str = NULL;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		str = ft_strjoin(str, ft_strndup(buffer, ret));
	fprintf(stderr, "%s\n", str);
	return (str);
}*/



int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	b_line = NULL;
	if(!(b_line = ft_strdup(buffer)))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		//printf("beg of read  loop\n");
		buffer[ret] = 0;
		printf("\nret : %d buffer :\n%s\n", ret, buffer);
		if ((buffer_el = ft_strchr(buffer, '\n')) != NULL)
		{
			printf("buffer_el = %s\n", buffer_el);
			if(!(*line = ft_strnjoin(b_line, buffer, buffer_el - buffer)))
				return (-1);
			ft_strcpy(buffer, buffer_el);
			return (1);
		}
		if (!(b_line = ft_strjoin(b_line, buffer)))
			return (-1);
	}
	return (0);
	// if ()
}
