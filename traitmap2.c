
#include "cub3d.h"

void	handleerror2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < param.num_rows)
	{
		j = 0;
		while (j < param.num_col)
		{
			if (mapp[i + 1][j + 1] != '0' && mapp[i + 1][j + 1] != '1' &&
				mapp[i + 1][j + 1] != '2' && mapp[i + 1][j + 1] != ' ' &&
				mapp[i + 1][j + 1] != 'N' && mapp[i + 1][j + 1] != 'E' &&
				mapp[i + 1][j + 1] != 'W' && mapp[i + 1][j + 1] != 'S')
			{
				printf("ERROR undefind caracter in Map");
				free(param.s5);
				free(mapp);
				exit(1);
			}
			if (mapp[i + 1][j + 1] == 'N' || mapp[i + 1][j + 1] == 'S' ||
				mapp[i + 1][j + 1] == 'W' || mapp[i + 1][j + 1] == 'E')
			{
				if (check.Player != 0)
				{
					free(mapp);
					free(param.s5);
					printf("double arguments on player");
					exit(1);
				}
				else
					check.Player = 1;
				traitrotaionangle(mapp[i + 1][j + 1]);
				param.i = i;
				param.j = j;
				mapp[i + 1][j + 1] = '0';
			}
			j++;
		}
		i++;
	}
}

void	find_zero_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < param.num_rows + 2)
	{
		j = 0;
		while (j < param.num_col + 2)
		{
			if (map[i][j] == '0')
			{
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' ||
					map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
				{
					printf("ERROE MAP NOT CLOS",
					map[i][j], map[i][j - 1], map[i][j + 1], map[i - 1][j],
					map[i + 1][j]);
					free(map);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
