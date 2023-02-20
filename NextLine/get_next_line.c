/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/20 13:12:36 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *statsh)
{
	char	*line;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (statsh == NULL || statsh[i] == '\0')
		return (NULL);
	while (statsh[len] != '\n' && statsh[len])
		len++;
	if (statsh[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	while (statsh[i] != '\n' && statsh[i])
	{
		line[i] = statsh[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*free_statsh(char *statsh)
{
	char	*str;
	int		i;

	i = 0;
	if (!statsh)
		return (NULL);
	while (statsh[i] && statsh[i] != '\n')
		i++;
	if (statsh[i] == '\n')
		i++;
	str = ft_strdup(statsh + i);
	if (statsh)
		free(statsh);
	return (str);
}

char	*buff_and_read(int fd, char *statsh)
{
	char	*buff;
	int		size;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = '\0';
		statsh = ft_strjoin(statsh, buff);
		if (ft_strchr(buff, '\n') == 1 || size <= -1)
			break ;
	}
	if (buff)
		free(buff);
	return (statsh);
}

char	*get_next_line(int fd)
{
	static char	*statsh = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	statsh = buff_and_read(fd, statsh);
	if (!statsh)
		statsh = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = ft_line(statsh);
	if (statsh)
		statsh = free_statsh(statsh);
	if (!line || !statsh)
	{
		if (statsh)
			free(statsh);
		return (NULL);
	}
	return (line);
}
