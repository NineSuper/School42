/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/17 11:35:49 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *line, char *statsh)
{
	int	j;
	int	i;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (statsh[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	while (statsh[j] != '\n')
		line[i++] = statsh[j++];
	return (line);
}

char	*free_statsh(char *statsh)
{
	int	i;

	i = 0;
}

char	*buff_and_read(int fd, char *buff, char *statsh)
{
	int	size;
	char	n;

	n = '\n';
	while (size != 0 && ft_strchr(buff, n) == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (!statsh)
			statsh = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		statsh = ft_strjoin(statsh, buff);
	}
	return (statsh);
}

char	*get_next_line(int fd)
{
	static char	*statsh;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) > 0)
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
