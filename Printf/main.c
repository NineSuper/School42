/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:25:14 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/22 11:03:56 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char	*str;

	str = "Chaine de caracteres\n";

	printf ("\n\n\t\033[42;01mFT_PRINTF\033[00m\n\n");
	ft_printf("TEXT\n");
	ft_printf("LETTE : %c\n");
	/*
			FONCTION PRINTF DE BASE
	*/
	printf ("\n\n\t \033[40;01mPRINTF\033[00m\n\n");
	printf("TEXTE\n");
	printf("Lettre : %c\n", 'c');
	printf("%s", str);
	printf("Pointeur %p\n", str);
	printf("Decimal : %d\n", 404);
	printf("Entier : %i\n", 42);
	printf("Decimal : %u\n", 12);
	printf("Hexadecimal.MAJ : %x\n", 2555);
	printf("Hexadecimal.min : %X\n", 2555);
	printf("Pourcentage%%");
}