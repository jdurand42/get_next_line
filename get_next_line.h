/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:24:32 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/21 19:12:29 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strcat(char *dest, char const *src);
int		parse_line(char *buffer, char *buffer_el, char **line, char *b_line);
int		parse_line2(char *buffer, char *buffer_el, char **line, char *b_line);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
size_t	ft_strlen(char const *str);
char	*ft_strndup(char const *src, size_t n);
char	*ft_strncat(char *dest, char const *src, size_t nb);
//char	*ft_strdup(char const *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);

#endif
