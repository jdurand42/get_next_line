/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 14:53:15 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *parse_test(int fd, char *buffer)
{
	int ret;
	char *str;

	str = NULL;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		str = ft_strjoin(str, ft_strndup(buffer, ret));
	fprintf(stderr, "%s\n", str);
	return (str);
}



int	get_next_line(int fd, char **line)
{
	char		*s;
	int 		ret;
	int 		i;
	static char		buffer[BUFFER_SIZE + 1];

	i = 0;
	if (!(*line = ft_strndup(buffer, ft_strnchr(buffer, '\n', BUFFER_SIZE))))
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	if (fd => 0)
		while ((ret = read(fd, buffer, BUFFER_SIZE) > 0)
		{
			buffer[ret] = 0;
			while (buffer[i] != 0 && buffer[i] != '\n')
				i++;
			if (buffer[i] == '\n') // We got a line;
			{
				if(!(*line = ft_strnjoin(*line, buffer, i)))
					return (-1);
				return (1);
			}
			*line = ft_strjoin(*line, buffer);
		}
		if !(*line)
			return (1);
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
