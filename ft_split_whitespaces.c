/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:45:36 by aali-mou          #+#    #+#             */
/*   Updated: 2019/09/12 22:54:29 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		taille(char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i + 1] != '\0' && s[i + 1] != ' '
					&& s[i + 1] != '\t' && s[i + 1] != '\n')
				count++;
		}
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		is_wspaces;

	i = -1;
	j = 0;
	is_wspaces = 1;
	if (!(tab = (char**)malloc(sizeof(char*) * (taille(str) + 1))))
		return (0);
	while (str[++i])
	{
		if (is_wspaces && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			tab[j++] = &str[i];
			is_wspaces = 0;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			str[i] = '\0';
			is_wspaces = 1;
		}
	}
	tab[j] = 0;
	return (tab);
}
