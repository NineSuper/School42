/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:06:33 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/23 11:49:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*str;
	char	*nul;
	int	one = 0;
	int	two = 0;
	int	c = 32;

	str = "Chaine de caracteres";

	printf ("\n\n\t\033[42;01m      FT_PRINTF       \033[00m\n\n");
	one += ft_printf("TEXTE\n");
	one += ft_printf("Lettre : %c %c %c\n", 'M', 'D', 'R');
	one += ft_printf("Chaine : %s  | NULL : %s\n", str, nul);
	one += ft_printf("Vide : %s %s\n", "", "");
	one += ft_printf("Pointeur : %p %p\n", str, nul);
	one += ft_printf("Decimal : %d %d\n", 404, -2147483648);
	one += ft_printf("Entier : %i %i\n", 42, -2147483648);
	one += ft_printf("Les x : %x %X %x %x %X\n", 96845997, 976455, -325342, -23333333, -845454);
	one += ft_printf("Decimal non signe : %u\n", 12);
	one += ft_printf("Hexadecimal.MAJ : %x %x %x %x %x %x\n", 2555, 666, 123, 1, 5999999, 4242);
	one += ft_printf("Hexadecimal.Min : %X %X %X %X %X %X\n", 2555, 666, 123, 1, 5999999, 4242);
	one += ft_printf("Pourcentage%%\n");
	one += ft_printf("%s\n", NULL);
	while (c <= 126)
	{
		one += ft_printf(" -%c               -%c               -%c               -%c               -%c\n", c, c + 1, c + 2, c + 3, c + 4);
		c = c + 5;
	}
	/*
			FONCTION PRINTF DE BASE
	*/
	printf("\n\n\t \033[40;01m       PRINTF       \033[00m\n\n");
	two += printf("TEXTE\n");
	two += printf("Lettre : %c %c %c\n", 'M', 'D', 'R');
	two += printf("Chaine : %s  | NULL : %s\n", str, nul);
	two += printf("Vide : %s %s\n", "", "");
	two += printf("Pointeur : %p %p\n", str, nul);
	two += printf("Decimal : %d %d\n", 404, -2147483648);
	two += printf("Entier : %i %i\n", 42, -2147483648);
	two += printf("Les x : %x %X %x %x %X\n", 96845997, 976455, -325342, -23333333, -845454);
	two += printf("Decimal non signe : %u\n", 12);
	two += printf("Hexadecimal.MAJ : %x %x %x %x %x %x\n", 2555, 666, 123, 1, 5999999, 4242);
	two += printf("Hexadecimal.Min : %X %X %X %X %X %X\n", 2555, 666, 123, 1, 5999999, 4242);
	two += printf("Pourcentage%%\n");
	two += printf("%s\n", NULL);
	c = 32;
	while (c <= 126)
	{
		two += printf(" -%c               -%c               -%c               -%c               -%c\n", c, c + 1, c + 2, c + 3, c + 4);
		c = c + 5;
	}
	if (one == two)
		printf("\n\n\t \033[44;01m    PARFAIT : %d/%d    \033[00m", one, two);
	else
		printf("\n\n\t \033[45;01m    KO : %d/%d   \033[00m", one, two);
}
