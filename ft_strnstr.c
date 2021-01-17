/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:47:04 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 23:40:16 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int pos;
	unsigned int i;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	pos = 0;
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			i = 0;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i]
					&& (pos + (ft_strlen(needle) - 1)) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&haystack[pos]);
		}
		++pos;
	}
	return (0);
}
