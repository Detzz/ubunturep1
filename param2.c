#include "cub3d.h"

void	checkresolutionparam(int check, char **s)
{
	if (check != 0)
	{
		printf("ERROR Double parametre Of FLOORc");
		free(s);
		exit(0);
	}
	else
		check = 1;
}

int		resolution(char *line)
{
	char	**s;
	int		j;

	s = ft_split_whitespaces(line);
	checkResolutionparam(check.Resolution, s);
	if (s[3] != '\0')
	{
		printf("ERROR MORE THAN 3 ARGUMENTS");
		free(s);
		exit(0);
	}
	checkdigit(s, 1);
	checkdigit(s, 2);
	if (atoi(s[1]) > 2560)
		param.g_width = 2560;
	else
		param.g_width = atoi(s[1]);
	if (atoi(s[2]) > 1440)
		param.g_height = 1440;
	else
		param.g_height = atoi(s[2]);
	free(s);
}

void init(void)
{
	g_cord.x = (TITLESIZE * param.j) + TITLESIZE / 2;
	g_cord.y = (TITLESIZE * param.i) + TITLESIZE / 2;
	g_cord.walkdirection = 0;
	g_cord.turndirection = 0;
	g_cord.movespeed = 8.0;
	g_cord.rotationspeed = 4 * (M_PI / 180);
	g_cord.wallhorhitx = 0;
	g_cord.wallhorhity = 0;
	g_cord.wallverhitx = 0;
	g_cord.wallverhity = 0;
	g_foundvertwallhit = 0;
	g_foundhortwallhit = 0;
	g_wallhitx = 0;
	g_wallhity = 0;
	g_walltexture = (int*)malloc(sizeof(int) * texturewidth *  textureheight);
	TEXTUREANALYSE();
}
