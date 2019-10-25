/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/25 13:03:41 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			pc;
	char			*str;

	str = (char *)s;
	i = 0;
	pc = (char)c;
	while (str[i] != 0)
	{
		if (str[i] == pc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int		parse_line2(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if (!(*line = ft_strnjoin(b_line, buffer, buffer_el - buffer)))
		return (-1);
	//printf("buffer_el: %s\n", buffer_el);
	ft_strcpy(buffer, buffer_el + 1);
	b_line = NULL;
	return (1);
}

int		parse_line(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if (!(*line = ft_strndup(b_line, buffer_el - b_line)))
		return (-1);
	ft_strcpy(buffer, buffer_el + 1);
	free(b_line);
	b_line = NULL;
	return (1);
}

int		parse_line3(char **line, char *b_line)
{
	if (!(*line = strndup(b_line, ft_strlen(b_line))))
		return (-1);
	free(b_line);
	b_line = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		buffer_nul[1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	if (fd < 0 || read(fd, buffer_nul, 0) < 0 ||
		!(b_line = ft_strndup(buffer, BUFFER_SIZE)))
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
	//	printf("%s\n", b_line);
	}
	buffer[ret] = 0;
	//printf("%s\n", b_line);
	return (parse_line3(line, b_line));
}
