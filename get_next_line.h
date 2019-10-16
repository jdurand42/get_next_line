/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:24:32 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 16:42:29 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
char 	*parse_test(int fd, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *src);
size_t	ft_strlen(char const *str);
char	*ft_strndup(char const *src, size_t n);
