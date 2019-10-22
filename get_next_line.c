/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/22 15:07:47 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
/*
char	*ft_strcat(char *dest, char const *src)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/
/*
char	*ft_strdup(char const *src)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	i = 0;
	len = ft_strlen(src);
	if (!src)
		return (NULL);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}*/
/*
char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	megasize;
	char			*b;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	megasize = ft_strlen(s1) + ft_strlen(s2);
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strcat(b, s1);
	ft_strcat(b, s2);
	return (b);
}*/

char	*ft_strncat(char *dest, char const *src, size_t nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

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

char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	unsigned int	megasize;
	char			*b;

	if (!s1 && s2)
		return (ft_strndup(s2, n));
	else if (!s2 && s1)
		return (ft_strndup(s1, ft_strlen(s1)));
	else if (!s1 && !s2)
		return (NULL);
	megasize = ft_strlen(s1) + n;
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strncat(b, s1, ft_strlen(s1));
	free((char*)s1);
	ft_strncat(b, s2, n);
	return (b);
}

char	*ft_strndup(char const *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

int	parse_line2(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if(!(*line = ft_strnjoin(b_line, buffer, buffer_el - buffer)))
		return (-1);
	ft_strcpy(buffer, buffer_el + 1);
	//free(b_line);
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

int	parse_line3(char **line, char *b_line)
{
	if (!(*line = strndup(b_line, ft_strlen(b_line))))
		return (-1);
	free(b_line);
	b_line = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	char		buffer_nul[1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	if (fd < 0 || read(fd, buffer_nul, 0) < 0 ||
		!(b_line = ft_strndup(buffer, BUFF_SIZE)))
		return (-1);
	//if(!(b_line = ft_strndup(buffer, BUFF_SIZE)))
	//	return (-1);
	if ((buffer_el = ft_strchr(b_line, '\n')) != NULL)
		return (parse_line(buffer, buffer_el, line, b_line));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if ((buffer_el = ft_strchr(buffer, '\n')) != NULL)
			return (parse_line2(buffer, buffer_el, line, b_line));
		if (!(b_line = ft_strnjoin(b_line, buffer, BUFF_SIZE)))
			return (-1);
	}
	buffer[ret] = 0;
	//(b_line[0] != 0) ? (return(parse_line3(line, b_line)) : (free(*line));
	if (b_line[0] != 0)
		return (parse_line3(line, b_line));
	free(*line);
	*line = NULL;
	return (0);
}
