/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/21 14:53:11 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	b_line = NULL;
	buffer_el = NULL;
	if(!(b_line = ft_strdup(buffer)))
		return (-1);
	if ((buffer_el = ft_strchr(b_line, '\n')) != NULL)
	{
		if(!(*line = ft_strndup(b_line, buffer_el - b_line)))
			return (-1);
		ft_strcpy(buffer, buffer_el + 1);
		return (1);
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if ((buffer_el = ft_strchr(buffer, '\n')) != NULL)
		{
			if(!(*line = ft_strnjoin(b_line, buffer, buffer_el - buffer)))
				return (-1);
			ft_strcpy(buffer, buffer_el + 1);
			return (1);
		}
		if (!(b_line = ft_strjoin(b_line, buffer)))
			return (-1);
	}
	return (0);
}
