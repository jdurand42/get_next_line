/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/21 20:58:15 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	parse_line2(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if(!(*line = ft_strnjoin(b_line, buffer, buffer_el - buffer)))
		return (-1);
	ft_strcpy(buffer, buffer_el + 1);
	free(b_line);
	return (1);
}

int	parse_line(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if(!(*line = ft_strndup(b_line, buffer_el - b_line)))
		return (-1);
	ft_strcpy(buffer, buffer_el + 1);
	free(b_line);
	b_line = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	if (fd < 0)
		return (-1);
	if(!(b_line = ft_strndup(buffer, BUFFER_SIZE)))
		return (-1);
	if ((buffer_el = ft_strchr(b_line, '\n')) != NULL)
		return (parse_line(buffer, buffer_el, line, b_line));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if ((buffer_el = ft_strchr(buffer, '\n')) != NULL)
			return (parse_line2(buffer, buffer_el, line, b_line));
		if (!(b_line = ft_strnjoin(b_line, buffer, BUFFER_SIZE)))
			return (-1);
	}
	buffer[0] = 0;
	if (b_line[0] != 0)
	{
		if (!(*line = strndup(b_line, ft_strlen(b_line))))
			return (-1);
		free(b_line);
		b_line = NULL;
		return (1);
	}
	free(*line);
	*line = NULL;
	return (0);
}
