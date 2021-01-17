#include "cub3d.h"
int		taillestandard(char *s, char c )
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != '\0' && s[i + 1] != c)
				count++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char c )
{
	char	**tab;
	int		i;
	int		j;
	int		is_wspaces;

	i = -1;
	j = 0;
	is_wspaces = 1;
	if (!(tab = (char**)malloc(sizeof(char*) * (taillestandard(str, c) + 1))))
		return (0);
	while (str[++i])
	{
		if (is_wspaces && str[i] != c)
		{
			tab[j++] = &str[i];
			is_wspaces = 0;
		}
		else if (str[i] == c )
		{
			str[i] = '\0';
			is_wspaces = 1;
		}
	}
	tab[j] = 0;
	return (tab);
}