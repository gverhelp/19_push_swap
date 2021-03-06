/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_malloc_s(char const *s, char c)
{
	int	a;
	int	counter;

	a = 0;
	counter = 0;
	while (s[a] != '\0')
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
		if (s[a] != '\0' && s[a] != c)
		{
			counter++;
			while (s[a] != '\0' && s[a] != c)
				a++;
		}
	}
	return (counter);
}

static void	ft_free(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		free(tab[a]);
		a++;
	}
	free(tab);
}

static char	*ft_write(const char *s, char c, char **tab)
{
	size_t	a;
	char	*dest;

	a = 0;
	while (s[a] != '\0' && s[a] != c)
		a++;
	dest = ft_substr(s, 0, a);
	if (dest == NULL)
		ft_free(tab);
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	int		b;
	char	**tab;

	a = 0;
	b = 0;
	if (s == NULL)
		return (NULL);
	tab = malloc((ft_malloc_s(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[a] != '\0')
	{
		while (s[a] == c)
			a++;
		if (s[a] != '\0' && s[a] != c)
		{
			tab[b++] = ft_write(&s[a], c, tab);
			while (s[a] != c && s[a] != '\0')
				a++;
		}
	}
	tab[b] = NULL;
	return (tab);
}
