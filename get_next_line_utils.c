/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:32:08 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/21 18:53:49 by jdurand          ###   ########.fr       */
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
}
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
	ft_strcat(b, s1);
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
