/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:37 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/17 12:41:35 by tde-los-         ###   ########.fr       */
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
	if (statsh[i] == '\0')
		return (NULL);
	while (statsh[len] != '\n' && statsh[len])
		len++;
	if (statsh[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	while (statsh[j] != '\n' && statsh[j])
		line[i++] = statsh[j++];
	line[i] = 0;
	return (line);
}

char	*free_statsh(char *statsh)
{
	char	*str;
	int		i;

	i = 0;
	while (statsh[i] && statsh[i] != '\n')
		i++;
	if (statsh[i] == '\n')
		i++;
	str = ft_strdup(statsh + i);
	free(statsh);
	return (str);
}

char	*buff_and_read(int fd, char *buff, char *statsh)
{
	char	n;
	int		size;

	n = '\n';
	while (size != 0 && ft_strchr(buff, n) == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = 0;
		statsh = ft_strjoin(statsh, buff);
	}
	return (statsh);
}

char	*get_next_line(int fd)
{
	static char	*statsh;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	line = NULL;
	statsh = buff_and_read(fd, buff, statsh);
	line = ft_line(line, statsh);
	statsh = free_statsh(statsh);
	if (buff)
		free(buff);
	buff = NULL;
	if (line == NULL)
		return (NULL);
	return (line);
}
