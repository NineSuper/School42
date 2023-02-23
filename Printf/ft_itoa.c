/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:55:46 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/23 11:38:49 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrev(char *str, int i, int n, int signe)
{
	while (i >= 0)
	{
		str[i] = (signe * (n % 10)) + 48;
		n = n / 10;
		i--;
	}
	if (signe == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;
	int		len;

	signe = 1;
	len = 1;
	i = n;
	if (n < 0)
	{
		signe = -1;
		len = 2;
	}
	while (i / 10 != 0)
	{
		len++;
		i /= 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	str = ft_strrev(str, i, n, signe);
	return (str);
}
