/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:44:22 by tde-los-          #+#    #+#             */
/*   Updated: 2023/03/02 17:03:56 by tde-los-         ###   ########.fr       */
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

char	*new_str()
{
	char	*str;
	int	len;

	ft_printf("\33[1;30m--Nouveau message--\33[00m\n");
	str = get_next_line(0);
	len = ft_strlen(str);
	str[len] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	char	*str;
	pid_t	pid;
	int	i;
	int	len;

	i = 0;
	if (argc != 2)
	{
		ft_printf("\33[1;31m❌Erreur : ./client <pid> !\33]00m");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_printf("\33[1;32m✅Vous etes bien connecte au PID: %d \n\33]00m", pid);
	str = malloc(sizeof(char) * 1);
	while (str != NULL)
	{
		if (str[i] == '\0')
		{
			str = new_str();
			i = 0;
		}
		ft_bits(pid, str[i++]);
	}
	return (0);
}
