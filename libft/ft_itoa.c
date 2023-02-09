/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:23 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/09 21:07:59 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_itoa(int n)
{
    char    *str;
    int     signe;
    int     len;
    int     i;

    signe = 1;
    len = 1;
    i = n;
    if (n < 0)
    {
        signe = -1;
        len = 2;
    }
    while ((i = i / 10))
        len++;
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    i = len - 1;
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