/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:32 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/06 10:04:49 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dtemp;
	const char	*stemp;

	dtemp = (char *)dest;
	stemp = (char *)src;
	while (n--)
		*dtemp++ = *stemp++;
	return (dest);
}
