/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:52 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/20 13:04:28 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int     main()
{
        int     fd;
	char	*line;
	int		i;

	i = 0;
        fd = open("texte", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("\033[42;01mLINE :\033[00m %s\n", line);
		free(line);
		i++;
	}
	fd = open("texte2.txt", O_RDONLY);
	printf("\n\n\nPARTIE 2\n\n\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("\033[42;01mLINE :\033[00m %s\n", line);
		free(line);
	}
	return (0);
}
