#include "cub3d.h"

void analyse(char *line)
{
	int i = 0;
	int j = 0;
	if (line[0] == ' ' || line [0] == '1')
	{
		s = ft_strjoin(s,line);
		//printf("%s \n",line);
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
void texture(char *line)
{
	char **s;
	int j;

	s = ft_split_whitespaces(line);
	if (s[2] != '\0')
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		exit(0);
	}
	if(s[0][0] == 'N' && s[0][1] == 'O' )
		tex.file[0] = strdup(s[1]);
	if(s[0][0] == 'S' && s[0][1] == 'O')
		tex.file[1] = strdup(s[1]);
	if(s[0][0] == 'W' && s[0][1] == 'E' )
		tex.file[2] = strdup(s[1]);
	if(s[0][0] == 'E' )
		tex.file[3] = strdup(s[1]);
	if(s[0][0] == 'S' && s[0][1] != 'O')
		tex.file[4] = strdup(s[1]);
}
void read_line()
{
	int fd;
	char *line;
	fd = open("map.cub", O_RDONLY);
	s = strdup("");
	g_spritecount = 0;
	while (get_next_line(fd, &line) != 0 )
	{
		analyse(line);
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
	printf("i m heeeere fucking here  \n");

	while (i < param.num_rows + 2)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
			{
				if ( map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ' )
				{
					printf("ERROE MAP NOT CLOSED %d /// %d",i,j);
					free(map);
					exit(1);
				}
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
	char *tmp;
	param.s5= ft_split(string,'\n');
	function_readingmaptogivespritecount(param.s5);
	while (param.s5[i] != '\0')
	{
		i++;
	}
	param.num_rows = i;
	int top;
	i = 0;
	top = 0;
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
		g_sp = malloc(sizeof(g_param) * (g_spritecount + 1));
	param.num_col =  top ;
	char **map;
	map = malloc(sizeof(char*) * (param.num_rows + 3));
	i = 0;
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

	i = 0;
	

	i = 0;
	while (i < param.num_rows)
	{

		j = 0;
		while (param.s5[i][j] != '\0')
		{

			map[i + 1][j + 1] = param.s5[i][j];
			j++;
		}
		i++;
		printf("im fucking here i = %d \n",i);
	}
		

	i = 0;
	while ( i < param.num_rows + 2)
	{
		j = 0;
		while (j < param.num_col + 2)
		{
			printf("%c",map[i ][j ]);
			j++;
		}
		printf("\n");
		
		i++;
	}
	
	find_zero_in_map(map);
 	i = 0;
	int k = 0;
	while (i < param.num_rows )
	{
		j = 0;
		while (j < param.num_col )
		{
			//if (param.s5[i][j] == ' ')
			//	param.s5[i][j] = '1';
			if (map[i +1][j+1] != '0' &&map[i + 1][j +1] != '1' && map [i + 1][j + 1] != '2' && map[i + 1][j + 1] != ' ' && map[i + 1][j + 1] != 'P')
				map[i + 1][j + 1] = ' ';
			
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
	i = 0;
}
void CEILLINGCOLOR(char *line)
{
	char **s;
	char **S;
	int a;
	int b;
	int c;
	s = ft_split_whitespaces(line);
	S = ft_split_virgules(s[1]);
	if(s[2] != '\0')
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		exit(0);
	}
	if(S[3] != '\0')
	{
	printf("ERROR MORE THAN 3 ARGUMENTS ");
	free(S);
	free(s);
	exit(0);

	}
	a = ft_atoi(S[0]);
	if ( a < 0)
	a = 0;
	else if (a > 255)
	a = 255;
	b = ft_atoi(S[1]);
	if ( b < 0)
	b = 0;
	else if (b > 255)
	b = 0;
	c = ft_atoi(S[2]);
	if (c < 0)
	c = 0;
	else if (c > 255)
	c = 255;
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
		if (s[2] != '\0')
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		exit(0);
	}
	if(S[3] != '\0')
	{
	printf("ERROR MORE THAN 3 ARGUMENTS ");
	free(S);
	free(s);
	exit(0);

	}

	a = ft_atoi(S[0]);
	if ( a < 0)
	a = 0;
	else if (a > 255)
	a = 255;
	b = ft_atoi(S[1]);
	if ( b < 0)
	b = 0;
	else if (b > 255)
	b = 0;
	c = ft_atoi(S[2]);
	if (c < 0)
	c = 0;
	else if (c > 255)
	c = 255;
	param.Florcolor = createRGB(a,b,c);
}

int resolution(char *line)
{
	int c;
	int d;
	char **s;
	c = 0;
	s = ft_split_whitespaces(line);
	if (s[3] != '\0')
	{
		printf("ERROR MORE THAN 3 ARGUMENTS");
		free(s);
		exit(0);
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


