#include "cub3d.h"
int		taillevirgules(char *s)
{
	int	i;
	int	count;
	virgulecount = 0;

	i = -1;
	count = 1;
	while (s[++i])
	{
		if (s[i] == ',')
		{
			virgulecount++;
			if (s[i + 1] != '\0' && s[i + 1] != ',')
				count++;
		}
	}
	return (count);
}

char	**ft_split_virgules(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		is_wspaces;

	i = -1;
	j = 0;
	is_wspaces = 1;
	if (!(tab = (char**)malloc(sizeof(char*) * (taillevirgules(str) + 1))))
		return (0);
	while (str[++i])
	{
		if (is_wspaces && str[i] != ',')
		{
			tab[j++] = &str[i];
			is_wspaces = 0;
		}
		else if (str[i] == ',' )
		{
			str[i] = '\0';
			is_wspaces = 1;
		}
	}
	tab[j] = 0;
	return (tab);
}