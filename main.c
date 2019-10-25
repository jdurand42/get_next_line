/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:40:37 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/25 13:06:48 by jdurand          ###   ########.fr       */
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
	//int 	i = 0;
	int		ret_gnl;
//	int 	choice = 5;

	//fprintf(stderr, "BUFFER_SIZE: %d\n", BUFFER_SIZE);
	if ((fd = open("lorem.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd2 = open("1.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd3 = open("test_folder", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	if ((fd4 = open("bible5.txt", O_RDONLY)) < 0)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier, fd: %d\n", fd);
		return (0);
	}
	//fprintf(stderr, "ficher ouvert, gg, fd: %d\n", fd4);
	//fprintf(stderr, "BUFFER_SIZE: %d\n", BUFFER_SIZE);
	//printf("type 0 for testing stdin\n");
//	scanf("%d\n", &choice);
	//getc(stdin);
//	if (choice == 0)
// /		fd = 0;

//	printf("hors loop: %d\n", get_next_line(-25, &line));
	while ((ret_gnl = get_next_line(fd4, &line)) == 1)
	{
		printf("%s\n", line);
		printf("ret in loop: %d\n", ret_gnl);
	//	i++;
		//if (i == 5)
		//	close(fd4);
	}
	printf("last ret: %d\n", ret_gnl);
	printf("%s\n", line);
}
