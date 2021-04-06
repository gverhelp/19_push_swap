/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (s == 0)
		return ;
	while (s[a] != '\0')
	{
		ft_putchar_fd(s[a], fd);
		a++;
	}
	write(fd, "\n", 1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0' &&
		(unsigned char)s1[a] == (unsigned char)s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int					a;
	int					plusmoins;
	unsigned long int	rep;

	a = 0;
	rep = 0;
	plusmoins = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			plusmoins *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		rep = rep * 10 + str[a] - 48;
		a++;
	}
	if (rep > 2147483648)
		return ((plusmoins == -1) ? 0 : -1);
	return (rep * plusmoins);
}
