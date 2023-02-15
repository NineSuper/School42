/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/15 17:00:48 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *line, char *statsh)
{
	int	i;

	i = 0;
	if (statsh == NULL || statsh[0] == '\0')
		return (NULL);
	while (statsh[i] && statsh[i] != '\n')
	{
		line[i] = statsh[i];
		i++;
	}
	//printf("STATSH : %s", statsh);
	line[i] = '\0';
	return (line);
}

char	*buff_and_read(int fd, char *statsh, int size)
{
	int		j;
	int		i;
	char	*buff;

	i = 0;
	j = 0;
	statsh = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, buff, BUFFER_SIZE);
	//printf("SIZE : %d\n", size);
	while (statsh[i] != '\n' && buff[i] && i < size)
		statsh[j++] = buff[i++];
	statsh[j] = '\0';
	return (statsh);
}

char	*get_next_line(int fd)
{
	static char	*statsh = NULL;
	char	*line;
	int		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size = 1;
	line = NULL;
	line = malloc(sizeof(char) * 100);
	statsh = buff_and_read(fd, statsh, size);
	line = ft_line(line, statsh);
	if(line == NULL)
		return (NULL);
	return (line);
}
