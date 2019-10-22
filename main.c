/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:40:37 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/22 15:10:15 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
	int 	fd;
	int 	fd2;
	int 	fd3;
	int		fd4;
	char 	*line;
	int		ret_gnl;
//	int 	choice = 5;

	//fprintf(stderr, "BUFFER_SIZE: %d\n", BUFFER_SIZE);
	if ((fd = open("lorem.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd2 = open("empty.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd3 = open("test_folder", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd4 = open("bible.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	//fprintf(stderr, "ficher ouvert, gg, fd: %d\n", fd4);
	fprintf(stderr, "BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf("type 0 for testing stdin\n");
//	scanf("%d\n", &choice);
	//getc(stdin);
//	if (choice == 0)
// /		fd = 0;
	while ((ret_gnl = get_next_line(fd4, &line) == 1))
	{
		printf("%d\n", ret_gnl);
		printf("%s\n", line);
		;
	}
	//printf("%d\n", ret_gnl);
	//printf("%s", line);
}
