/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:25:14 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/22 15:57:05 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char	*str;
	char	*nul;
	int	count = 0;

	str = "Chaine de caracteres";

	printf ("\n\n\t\033[42;01mFT_PRINTF\033[00m\n\n");
	ft_printf("%d\n", ft_printf("TEXTE\t"));
	ft_printf("Lettre : %c %c %c\n", 'M', 'D', 'R');
	ft_printf("Chaine : %s  | NULL : %s\n", str, nul);
	ft_printf("Pointeur : %p\n", str);
	ft_printf("Decimal : %d\n", 404);
	ft_printf("Entier : %i\n", 42);
	ft_printf("Decimal non signe : %u\n", 12);
	ft_printf("Hexadecimal.MAJ : %x %x %x %x %x %x\n", 2555, 666, 123, 1, 5999999, 4242);
	ft_printf("Hexadecimal.Min : %X %X %X %X %X %X\n", 2555, 666, 123, 1, 5999999, 4242);
	ft_printf("Pourcentage%%\n");
	ft_printf("Autre % : %g %a %b %z %q\n");
	/*
			FONCTION PRINTF DE BASE
	*/
	printf ("\n\n\t \033[40;01mPRINTF\033[00m\n\n");
	printf("%d\n", printf("TEXTE\t"));
	printf("%d\n", printf("Lettre : %c %c %c\t", 'M', 'D', 'R'));
	printf("Chaine : %s  | NULL : %s\n", str, nul);
	printf("%s\n", str);
	printf("Pointeur %p\n", str);
	printf("Decimal : %d\n", 404);
	printf("Entier : %i\n", 42);
	printf("Decimal non signe : %u\n", 12);
	printf("Hexadecimal.MAJ : %x %x %x %x %x %x\n", 2555, 666, 123, 1, 5999999, 4242);
	printf("Hexadecimal.Min : %X %X %X %X %X %X\n", 2555, 666, 123, 1, 5999999, 4242);
	printf("Pourcentage%%\n");
}
