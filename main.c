#include "cub3d.h"

void analyse(char *line)
{
	int i = 0;
	int j = 0;
	char **d;
	if (line[0] == ' ' || line [0] == '1')
	{
		mapfinding = 1;
		s = ft_strjoin(s,line);
		s = ft_strjoin(s, "\n");
	}
	if (line[0] == 'R' && line[1] == ' ')
		resolution(line);
	if(line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		texture(line);
	if(line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		texture(line);
	if(line[0] == 'S' && line[1] == ' ' )
		texture(line);
	if(line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		texture(line);
	if(line[0] == 'E' && line[1] == 'A' )
		texture(line);
	if (line[0] == 'F' && line[1] == ' ')
		FLOORCOLOR(line);
	if (line[0] == 'C' && line[1] == ' ')
		CEILLINGCOLOR(line);
}


void	traitNotexture(char **s ,int fd)
{
	if(check.TextureNo != 0)
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
		if ((fd = open(tex.file[0],O_RDONLY) == -1))
		{
			printf("error there is no file");
			free (s);
			exit(1);
		}
}

void	TRAITSotexture(char **s,int fd)
{
	if(check.TextureSu != 0)
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
		if ((fd = open(tex.file[1],O_RDONLY) == -1))
		{
			printf("error there is no file");
			free (s);
			exit(1);
		}	
}

void	traitWetexture(char **s, int fd)
{
			if(check.TextureWe != 0)
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
		if ((fd = open(tex.file[2],O_RDONLY) == -1))
		{
			printf("error there is no file");
			free (s);
			exit(1);
		}
		}

void traitEstexture(char **s, int fd)
{
		if(check.TextureEa != 0)
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
		if ((fd = open(tex.file[3],O_RDONLY) == -1))
		{
			printf("error there is no file");
			free (s);
			exit(1);
		}
		
}
void	traitspactex(char **s,int fd)
{
	if(check.Sprite != 0)
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
			free (s);
			exit(1);
		}
}
void texture(char *line)
{
	char **s;
	int j;
	int fd;

	s = ft_split_whitespaces(line);
	if (s[2] != '\0')
	{
		printf("ERROR ");
		free(s);
		exit(0);
	}
	if(s[0][0] == 'N' && s[0][1] == 'O' )
	traitNotexture(s,fd);
	if(s[0][0] == 'S' && s[0][1] == 'O')
	TRAITSotexture(s,fd);
	if(s[0][0] == 'W' && s[0][1] == 'E' )
	traitWetexture(s,fd);
	if(s[0][0] == 'E' )
	traitEstexture(s,fd);
	if(s[0][0] == 'S' && s[0][1] != 'O')
	traitspactex(s,fd);
}
void init_param(void)
{
	check.Resolution = 0;
	check.TextureNo = 0;
	check.TextureSu = 0;
	check.TextureWe = 0;
	check.TextureEa = 0;
	check.Sprite = 0;
	check.Floor = 0;
	check.Ceillig = 0;
}
void read_line()
{
	int fd;
	char *line;
	init_param();
	fd = open("map.cub", O_RDONLY);
		linecount = 0;

	s = strdup("");
	g_spritecount = 0;
	while (get_next_line(fd, &line) != 0 )
	{
		
		analyse(line);
		if(mapfinding == 1)
		linecount ++;
		free (line);
	}
	TREATMAP(s);
	free(line);
}
void find_zero_in_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param.num_rows + 2)
	{
		j = 0;
		while (j <param.num_col + 2)
		{	
			if (map[i][j] == '0')
			{
				if ( map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ' )
				{
					printf("i == %d j == %d\n",i,j);
					printf("ERROE MAP NOT CLOS i = |%c| /// j ==|%c|//  i - 1  == |%c| //  i + 1 == |%c| // j  + 1 == |%c|\n ",map[i][j],map[i][j - 1], map[i][j + 1] ,map[i - 1][j] ,map[i + 1][j]);
					free(map);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}	
	}

void	handleerroe1()
{
	if (linecount !=  param.num_rows)
	{
			printf("linecount == %d , num of rows == %d\n",linecount,param.num_rows);

		printf("ERROR MAP IS OPEN");
		free(param.s5);
		exit(1);

	}
}

void	findingnumofcols()
{
	int i;
	int top;
	int j;
	i = 0;
	while(i < param.num_rows)
	{
		j = 0;
		while (param.s5[i][j++] != '\0')
		{
			if (j > top)
				top = j;
		}
		i++;
	}
	param.num_col =  top ;

}

char **Remplirmap(char **map)

{
	int i;
	int j;

i = 0;

	g_sp = malloc(sizeof(g_param) * (g_spritecount + 1));
	map = malloc(sizeof(char*) * (param.num_rows + 3));
	while ( i < param.num_rows + 3)
	{
		map[i] = malloc(sizeof(char) * (param.num_col + 3));
		i++;
	}
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
	return(map);
}

char **Swappingmaps(char **map)

{	
	int i;
	int j;

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
return(map);

}

void	handleerror2(char **map)
{
	int i;
	int j;

	i = 0;
		while (i < param.num_rows )
	{
		j = 0;
		while (j < param.num_col )
		{
			if (map[i +1][j+1] != '0' &&map[i + 1][j +1] != '1' && map [i + 1][j + 1] != '2' && map[i + 1][j + 1] != ' ' && map[i + 1][j + 1] != 'P')		
				{
					printf("ERROR undefind caracter in Map");
		free(param.s5);
		free(map);
		exit(1);
		}
			if (map[i + 1][j + 1] == 'P')
			{
				param.i = i;
				param.j = j;
				map[i + 1][j + 1] = '0';
			} 
			j++;
		}
		i++;
	}
}
void TREATMAP(char *string)
{
	int i = 0;
	int j = 0;
		char **map;

	param.s5= ft_split(string,'\n');
	function_readingmaptogivespritecount(param.s5);
	while (param.s5[i] != '\0')
		i++;
	param.num_rows = i;
	findingnumofcols();
	map = Remplirmap(map);
	map = Swappingmaps(map);
	find_zero_in_map(map);
 	i = 0;
	handleerror2(map);
}
void	colorrangecheck(char **s,char **S)
{
	int i;
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(S[i]) < 0 ||ft_atoi(S[i]) > 255)
		{
			printf("ERROR COLOR OUT OF RANGE [0,255]");
			free (S);
			free(s);
			exit(1);
		}
		i++;
	}
}

void	checkfloorCeilingparam(int check,char **s,char **S)
{
		if(check != 0)
	{
		printf("ERROR Double parametre Of FLOORc");
		free(s);
		free(S);
		exit(0);
	}
	else
		check = 1;
}
void CEILLINGCOLOR(char *line)
{
	char **s;
	char **S;
	int a;
	int b;
	int c;
	int i;
	s = ft_split_whitespaces(line);
	S = ft_split_virgules(s[1]);
	checkfloorCeilingparam(check.Ceillig,s,S);

	if(s[2] != '\0' || S[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(S);
		exit(0);
	}
	i = 0;

	colorrangecheck(s,S);
	a = ft_atoi(S[0]);
	b = ft_atoi(S[1]);
	c = ft_atoi(S[2]);
	
	param.Ceillingcolor = createRGB(a,b,c);
}


void FLOORCOLOR(char *line)
{
	char **s;
	char **S;
	int a;
	int b;
	int c;
	
	s = ft_split_whitespaces(line);
	S = ft_split_virgules(s[1]);

	checkfloorCeilingparam(check.Floor,s,S);
if(s[2] != '\0' || S[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(S);
		exit(0);
	}
	colorrangecheck(s,S);
	a = ft_atoi(S[0]);
	b = ft_atoi(S[1]);
	c = ft_atoi(S[2]);
	param.Florcolor = createRGB(a,b,c);
}

int resolution(char *line)
{
	int c;
	int d;
	char **s;
	int j;
	c = 0;
	s = ft_split_whitespaces(line);
	if(check.Resolution != 0)
	{
		printf("ERROR Double parametre Of resolution");
		free(s);
		exit(0);
	}
	else
	{
		check.Resolution = 1;
	}
	
	if (s[3] != '\0')
	{
		printf("ERROR MORE THAN 3 ARGUMENTS");
		free(s);
		exit(0);
	}
	j= 0;
	 while (j <strlen(s[1]) )
	 {
		 
		 if (ft_isdigit(s[1][j]) == 1)
		 j++;
		 else
		 {
			 printf("ERROR WITDH IS NOT NUM");
			 free(s);
			 exit(1);
		 }
	 }
	 j= 0;
	while (j <strlen(s[2]))
	 {
		 if (ft_isdigit(s[2][j]) == 1)
		 j++;
		 else
		 {
			 printf("ERROR HEIGHT IS NOT NUM");
			 free(s);
			 exit(1);
		 }
		 
	 }
	if (atoi(s[1]) > 2560)
	param.g_width = 2560;
	else
	param.g_width  = atoi(s[1]);
	if(atoi(s[2]) > 1440)
	param.g_height = 1440;
	else
	param.g_height = atoi(s[2]);
	
	free (s);
	return(c);
}
void init()
{
	g_cord.x = (TITLESIZE * param.j) + TITLESIZE/ 2;
	g_cord.y = (TITLESIZE * param.i) + TITLESIZE/ 2;
	g_cord.rotationangle = (M_PI) / 2;
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
	g_walltexture =( int *) malloc(sizeof(int ) * TEXTUREWIDTH *  TEXTUREHEIGHT);
	TEXTUREANALYSE();

}

int g_tab[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}};

int main()
{

	read_line();
	init();
	init_sprite();
	
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, param.g_width, param.g_height, "mlx_abdel");
	img.img = mlx_new_image(g_mlx_ptr, param.g_width, param.g_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	lOADTEXRURE();
	mlx_hook(g_win_ptr,  2, 0, key_press, &g_cord);
		mlx_loop_hook(g_mlx_ptr,move_player,&g_cord);   

	mlx_hook(g_win_ptr, 3, 0, key_release, &g_cord);
	mlx_loop(g_mlx_ptr);
}


