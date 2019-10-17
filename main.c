/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:40:37 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 18:16:08 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char **line;
	char *str;
	char	buff[BUFFER_SIZE];
	int 	nbline = 0;

	if(!(line = (char**)malloc(sizeof(char*))))
		return (0);
	if ((fd = open("lorem.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	fprintf(stderr, "ficher ouvert, gg, fd: %d\n", fd);
	str = parse_test(fd, buff);
	nbline = nbline + get_next_line(fd, line);
}
