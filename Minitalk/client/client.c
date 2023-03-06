/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:44:22 by tde-los-          #+#    #+#             */
/*   Updated: 2023/03/06 19:04:09 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		bit++;
		usleep(800);
	}
}

char	*new_str(void)
{
	char	*str;
	int		len;

	ft_printf("\33[1;30m--Nouveau message--\33[00m\n> ");
	str = get_next_line(0);
	len = ft_strlen(str);
	str[len] = '\0';
	return (str);
}

pid_t	client_id(pid_t pid)
{
	char	*client;
	pid_t	client_pid;
	int		i;

	client_pid = getpid();
	client = ft_strjoin("|", ft_itoa(client_pid));
	client = ft_strjoin(client, "|");
	i = 0;
	while (client[i])
		ft_bits(pid, client[i++]);
	ft_printf("\33[1;201mPID client [%d]\n\33[00m", client_pid);
	return (client_pid);
}

int	main(int argc, char **argv)
{
	char	*str;
	pid_t	pid;
	pid_t	client_pid;
	int		i;
	int		len;

	i = 0;
	ft_printf("\33[1;130mEntrez le PID du server \33[00m");
	pid = ft_atoi(get_next_line(0));
	ft_printf("\33[1;32m✅Vous etes bien connecte au PID: %d \n\33[00m", pid);
	client_pid = client_id(pid);
	str = malloc(sizeof(char) * 1);
	while (str != NULL)
	{
		if (str[i] == '\0')
		{
			free(str);
			str = new_str();
			i = 0;
		}
		ft_bits(pid, str[i++]);
	}
	return (0);
}
