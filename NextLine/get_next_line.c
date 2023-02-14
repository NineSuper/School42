/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/14 10:18:34 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	statsh_line(char *buf)
{
	static char	*statsh;
	int	i;
	int	j;

	i = 0;
	j = 0;
	statsh = malloc(sizeof(char*) * 100);
	while(buf[i])
		statsh[j++] = buf[i++];
	printf("STATSH : %s\n", statsh);
}

char	*get_next_line(int fd)
{
	char	buf[100];
	char	statsh[100];
	size_t	i;
	size_t	j;

	read(fd, buf, 5);
	printf("BUFF : %s\n", buf);
	statsh_line(buf);
	read(fd, buf, 5);
	printf("BUFF : %s\n", buf);
	statsh_line(buf);
}

int	main()
{
	char	*file;
	int	fd;

	file = "texte";
	fd = open(file, O_CREAT, S_IWUSR | S_IRUSR);
	get_next_line(fd);
}
