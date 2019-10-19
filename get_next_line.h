/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:24:32 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/19 17:49:05 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 150
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strnnjoin(char const *s1, char const *s2, size_t n, size_t n2);
char	*ft_strdup(char const *src);
size_t	ft_strlen(char const *str);
char	*ft_strndup(char const *src, size_t n);
char	*ft_strncat(char *dest, char const *src, size_t nb);
char	*ft_strdup(char const *src);
char	*ft_strchr(const char *s, int c);
size_t	*ft_strchr_id(const char *s, int c, size_t n);

#endif
