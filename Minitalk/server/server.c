/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:11:32 by tde-los-          #+#    #+#             */
/*   Updated: 2023/03/02 17:05:59 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


static void	get_bits(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

void    ft_get_signal()
{

        signal(SIGUSR1, get_bits);
        signal(SIGUSR2, get_bits);
}

int	main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("\033[1;32m✅PID : %d\33[00m\n", pid);
	ft_printf("\033[1;30m---En attente d'un message client----\033[00m\n");
	while (1)
	{
		ft_get_signal();
		pause();
	}
}
