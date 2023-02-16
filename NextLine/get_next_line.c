/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/16 16:43:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *line, char *statsh)
{
	static int	j;
	int			i;

	i = 0;
	if (statsh == NULL || statsh[0] == '\0')
		return (NULL);
	while (statsh[i] != '\n' && statsh[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (statsh[j] && statsh[j] != '\n')
	{
		line[i] = statsh[j];
		i++;
		j++;
	}
	if (statsh[j] == '\n')
		j += 1;
	if (line[0] != '\0')
		line[i] = '\0';
	else
		return (NULL);
	return (line);
}

char	*buff_and_read(int fd, char *buff, char *statsh)
{
	int	j;
	int	i;
	int	size;

	i = 0;
	if (statsh == NULL)
	{
		statsh = malloc(sizeof(char) * (BUFFER_SIZE + 500));
		j = 0;
	}
	while (size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		while (buff[i])
			statsh[j++] = buff[i++];
		i = 0;
	}
	statsh[j] = '\0';
	return (statsh);
}

char	*get_next_line(int fd)
{
	static char	*statsh;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	statsh = buff_and_read(fd, buff, statsh);
	line = ft_line(line, statsh);
	free(buff);
	if (line == NULL)
		return (NULL);
	return (line);
}
