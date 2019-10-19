/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/19 17:45:38 by jdurand          ###   ########.fr       */
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
	char		*s;
	int 		ret;
	size_t 		i;
	char 		*buffer_el;
	char 		*line_el;
	//char		*line_buffer;
	static char		buffer[BUFFER_SIZE + 1];

	*line = ft_strdup(ft_strchr(buffer, '\n'));
//	printf("line in begloop: %s\n", *line);
	if (fd >= 0)
		while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[ret] = 0;
			i = 0;
			line_el = NULL;
			buffer_el = NULL;
			buffer_el = ft_strchr(buffer, '\n');
			if (*line)
				line_el = ft_strchr(*line, '\n');
			if (buffer_el)
			{
				if (!line_el)
					*line = ft_strnjoin(*line, buffer, buffer_el - buffer);
				else if (line_el)
					*line = ft_strnnjoin(*line , buffer, line_el - *line, buffer_el - buffer);
				return (1);
			}
			else if (!buffer_el)
				*line = ft_strjoin(*line, buffer);
		 // ca marche si BUFFER_SIZE < nb char de line
//			printf("line in endloop: %s\n", *line);
		}
	return (0);
}


/*
Checker d'abord dans une boucle de read jusqu'a;
checker jusqu'a ret si il y a un \n
if not
	reread de BUFFER_SIZE;
retourner la ligne
profit
*/
