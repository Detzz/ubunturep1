/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:06:26 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/27 16:52:40 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_instr(int c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == (char)c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		count;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	count = 0;
	while (is_instr(s1[start], set))
		start++;
	while (is_instr(s1[end - 1], set) && end > start)
		end--;
	strtrim = (char *)malloc((end - start + 1) * sizeof(char));
	if (!strtrim)
		return (NULL);
	while (count < (end - start))
	{
		strtrim[count] = (char)s1[count + start];
		count++;
	}
	strtrim[count] = '\0';
	return (strtrim);
}
