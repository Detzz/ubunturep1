
#include "cub3d.h"

void	treatmap(char *string)
{
	int	i;
	int j;
	int top;

	param.s5 = ft_split(string, '\n');
	function_readingmaptogivespritecount(param.s5);
	i = 0;
	while (param.s5[i] != '\0')
		i++;
	param.num_rows = i;
	i = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (param.s5[i][j++] != '\0')
		{
			if (j > top)
				top = j;
		}
		i++;
	}
	param.num_col = top;
	g_sp = malloc(sizeof(g_param) * (g_spritecount + 1));
	mapp = malloc(sizeof(char*) * (param.num_rows + 3));
	i = 0;
	while (i < param.num_rows + 3)
	{
		mapp[i] = malloc(sizeof(char) * (param.num_col + 3));
		i++;
	}
	Remplirmap(mapp);
	Swappingmaps(mapp);
	find_zero_in_map(mapp);
	handleerroe1();
	handleerror2(mapp);
}

void	**remplirmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < param.num_rows + 2)
	{
		j = 0;
		while (j < param.num_col + 2)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	**swappingmaps(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (param.s5[i][j] != '\0')
		{
			map[i + 1][j + 1] = param.s5[i][j];
			j++;
		}
		i++;
	}
}

void	handleerroe1(void)
{
	if (linecount != param.num_rows)
	{
		printf("ERROR MAP IS OPEN");
		free(param.s5);
		exit(1);
	}
}

void	findingnumofcols(void)
{
	int	i;
	int	top;
	int	j;

	i = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (param.s5[i][j++] != '\0')
		{
			if (j > top)
				top = j;
		}
		i++;
	}
	param.num_col = top;
}
