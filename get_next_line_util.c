/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:32:08 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 16:41:20 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*ft_strcat_bonus(char *dest, char const *src)
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

char	*ft_strdup(char const *src)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	i = 0;
	len = ft_strlen(src);
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
}

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
	if (megasize <= 0)
		return ("");
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strcat_bonus(b, s1);
	ft_strcat_bonus(b, s2);
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
