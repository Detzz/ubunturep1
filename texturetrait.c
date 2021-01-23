
#include "cub3d.h"

void	traitnotexture(char **s, int fd)
{
	if (check.TextureNo != 0)
	{
		printf("ERROR Double parametre Of TextureNo");
		free(s);
		exit(0);
	}
	else
	{
		check.TextureNo = 1;
	}
	tex.file[0] = strdup(s[1]);
	if ((fd = open(tex.file[0], O_RDONLY) == -1))
	{
		printf("error there is no file");
		free(s);
		exit(1);
	}
}

void	traitsotexture(char **s, int fd)
{
	if (check.TextureSu != 0)
	{
		printf("ERROR Double parametre Of Texture sou");
		free(s);
		exit(0);
	}
	else
	{
		check.TextureSu = 1;
	}
	tex.file[1] = strdup(s[1]);
	if ((fd = open(tex.file[1], O_RDONLY) == -1))
	{
		printf("error there is no file");
		free(s);
		exit(1);
	}
}

void	traitwetexture(char **s, int fd)
{
	if (check.TextureWe != 0)
	{
		printf("ERROR Double parametre Of Texturewe");
		free(s);
		exit(0);
	}
	else
	{
		check.TextureWe = 1;
	}
	tex.file[2] = strdup(s[1]);
	if ((fd = open(tex.file[2], O_RDONLY) == -1))
	{
		printf("error there is no file");
		free(s);
		exit(1);
	}
}

void	traitestexture(char **s, int fd)
{
	if (check.TextureEa != 0)
	{
		printf("ERROR Double parametre Of TextureEa");
		free(s);
		exit(0);
	}
	else
	{
		check.TextureEa = 1;
	}
	tex.file[3] = strdup(s[1]);
	if ((fd = open(tex.file[3], O_RDONLY) == -1))
	{
		printf("error there is no file");
		free(s);
		exit(1);
	}
}

void	traitspactex(char **s, int fd)
{
	if (check.Sprite != 0)
	{
		printf("ERROR Double parametre Of Sprite");
		free(s);
		exit(0);
	}
	else
	{
		check.Sprite = 1;
	}
	tex.file[4] = strdup(s[1]);
	if ((fd = open(tex.file[4], O_RDONLY) == -1))
	{
		printf("error there is no file");
		free(s);
		exit(1);
	}
}
