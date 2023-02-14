/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/14 15:35:13 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//JE CHIE SUR CE CODE ! Vraiment relou il fait pas ce que je veux zebi !

char	*ft_line(char *line, char *statsh)
{
	int	i;

	i = 0;
	while (statsh[i] && statsh[i] != '\n')
	{
		line[i] = statsh[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*statsh_line(char *buf, char *statsh, int size)
{
	static int	j;
	int			i;

	i = 0;
	if (statsh == NULL)
		j = 0;
	while (buf[i] && i < size)
		statsh[j++] = buf[i++];
	printf("STATSH : %s \t", statsh);
	return (statsh);
}

char	*get_next_line(int fd)
{
	char	buf[BUFF_SIZE];
	char	*statsh;
	char	*line;
	int		size;

	line = malloc(sizeof(char *) * 100);
	statsh = malloc(sizeof(char *) * 100);
	size = read(fd, buf, 7);
	printf("BUFFER : %s \t", buf);
	statsh = statsh_line(buf, statsh, size);
	printf("Size : %d \t", size);
	line = ft_line(line, statsh);
	return (line);
}
