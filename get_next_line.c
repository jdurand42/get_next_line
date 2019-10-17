/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/17 20:28:55 by jdurand          ###   ########.fr       */
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
	static char*s;
	static int id;
	int ret;
	int ret_count;
	int i;

	j = 0;
	ret = 0;
	i = 0;
	if (!s)
		s = NULL;
	while (ret = read(fd, buffer, BUFFER_SIZE) > 0);
	{
		s = ft_strnjoin(s, buffer, ret);
		while (s[i] == '\0')
		{
			if (s[i++] == '\n')
			{
				*line = ft_strndup(s, i - 1);
				if (i < ft_strlen(s))
					s = ft_strdup(&s[i + 1]);
			}
		}
		

}
/*
Checker d'abord dans une boucle de read jusqu'a;
checker jusqu'a ret si il y a un \n
if not
	reread de BUFFER_SIZE;
retourner la ligne
profit
*/
