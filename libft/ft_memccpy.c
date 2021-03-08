/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:45:30 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 16:11:02 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)src;
	while (n != 0)
	{
		*(unsigned char*)dest++ = *(unsigned char*)src++;
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dest++ = *(unsigned char*)src++;
			return (dest);
		}
		n--;
		str++;
	}
	return (0);
}
