/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:52 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/14 15:08:38 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int     main()
{
        int     fd;

        fd = open("texte", O_RDONLY);
	printf("1 : ");
	printf("line : %s\n", get_next_line(fd));
	printf("2 : ");
	printf("line : %s\n", get_next_line(fd));
	printf("3 : ");
	printf("line : %s\n", get_next_line(fd));
	printf("4 : ");
	printf("line : %s\n", get_next_line(fd));
	printf("5 : ");
	printf("line : %s\n", get_next_line(fd));
}
