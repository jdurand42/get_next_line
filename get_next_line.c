/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 17:24:04 by jdurand          ###   ########.fr       */
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
	
}
