/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/19 19:47:46 by jdurand          ###   ########.fr       */
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
	line_el = NULL;
//	printf("line in begloop: %s\n", *line);
	if ((buffer_el = ft_strchr(*line, '\n')) != *line)
	{
		*line = ft_strndup(*line, buffer_el - *line - 1);
		ft_strncpy(buffer, buffer_el, BUFFER_SIZE);
		printf("\nbuffer :%s\n\n", buffer);
		return (1);
	}
	if (fd >= 0)
		while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[ret] = 0;
			i = 0;
	//		printf("ret: %d, buffer in beg_read_loop: %s\n", ret, buffer);
			while (buffer[i] != 0 && buffer[i] != '\n')
				i++;
			if (buffer[i] == '\n') // We got a line;
			{
				if(!(*line = ft_strnjoin(*line, buffer, i)))
					return (-1);
				return (1);
			}
			*line = ft_strjoin(*line, buffer); // ca marche si BUFFER_SIZE < nb char de line
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
