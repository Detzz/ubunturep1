#include "cub3d.h"

void	analyse(char *line)
{
	if (line[0] == ' ' || line[0] == '1')
	{
		mapfinding = 1;
		s = ft_strjoin(s, line);
		s = ft_strjoin(s, "\n");
	}
	if (line[0] == 'R' && line[1] == ' ')
		resolution(line);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		texture(line);
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		texture(line);
	if (line[0] == 'S' && line[1] == ' ')
		texture(line);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		texture(line);
	if (line[0] == 'E' && line[1] == 'A')
		texture(line);
	if (line[0] == 'F' && line[1] == ' ')
		FLOORCOLOR(line);
	if (line[0] == 'C' && line[1] == ' ')
		CEILLINGCOLOR(line);
}

void	read_line(void)
{
	int		fd;
	char	*line;

	init_param();
	fd = open("map.cub", O_RDONLY);
	linecount = 0;
	s = strdup("");
	g_spritecount = 0;
	while (get_next_line(fd, &line) != 0)
	{
		analyse(line);
		if (mapfinding == 1)
			linecount++;
		free(line);
	}
	TREATMAP(s);
	free(line);
}

void	texture(char *line)
{
	char	**s;
	int		fd;

	s = ft_split_whitespaces(line);
	if (s[2] != '\0')
	{
		printf("ERROR ");
		free(s);
		exit(0);
	}
	if (s[0][0] == 'N' && s[0][1] == 'O')
		traitnotexture(s, fd);
	if (s[0][0] == 'S' && s[0][1] == 'O')
		traitsotexture(s, fd);
	if (s[0][0] == 'W' && s[0][1] == 'E')
		traitwetexture(s, fd);
	if (s[0][0] == 'E')
		traitestexture(s, fd);
	if (s[0][0] == 'S' && s[0][1] != 'O')
		traitspactex(s, fd);
}

void	traitrotaionangle(char c)
{
	if (c == 'N')
		g_cord.rotationangle = (1.5 * M_PI);
	if (c == 'E')
		g_cord.rotationangle = (2 * M_PI);
	if (c == 'W')
		g_cord.rotationangle = (M_PI);
	if (c == 'S')
		g_cord.rotationangle = (0.5 * M_PI);
}

void	init_param(void)
{
	check.Resolution = 0;
	check.TextureNo = 0;
	check.TextureSu = 0;
	check.TextureWe = 0;
	check.TextureEa = 0;
	check.Sprite = 0;
	check.Floor = 0;
	check.Ceillig = 0;
	check.Player = 0;
}
