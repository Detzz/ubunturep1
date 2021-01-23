#include "cub3d.h"

void	colorrangecheck(char **s, char **S)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(S[i]) < 0 || ft_atoi(S[i]) > 255)
		{
			printf("ERROR COLOR OUT OF RANGE [0,255]");
			free(S);
			free(s);
			exit(1);
		}
		i++;
	}
}

void	checkfloorCeilingparam(int check, char **s, char **S)
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
void	ceillingcolor(char *line)
{
	char	**s;
	char	**S;
	int		a;
	int		b;
	int		c;

	s = ft_split_whitespaces(line);
	S = ft_split_virgules(s[1]);
	checkfloorCeilingparam(check.Ceillig, s, S);
	if(s[2] != '\0' || S[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(S);
		exit(0);
	}
	colorrangecheck(s, S);
	a = ft_atoi(S[0]);
	b = ft_atoi(S[1]);
	c = ft_atoi(S[2]);
	param.Ceillingcolor = createRGB(a, b, c);
}


void	floorcolor(char *line)
{
	char	**s;
	char	**S;
	int		a;
	int		b;
	int		c;
	
	s = ft_split_whitespaces(line);
	S = ft_split_virgules(s[1]);
	checkfloorCeilingparam(check.Floor, s, S);
	if(s[2] != '\0' || S[3] != '\0' || virgulecount != 2)
	{
		printf("ERROR MORE THAN 2 ARGUMENTS");
		free(s);
		free(S);
		exit(0);
	}
	colorrangecheck(s, S);
	a = ft_atoi(S[0]);
	b = ft_atoi(S[1]);
	c = ft_atoi(S[2]);
	param.Florcolor = createRGB(a, b, c);
}

void	checkdigit(char **s, int i)
{
	int	j;

	j = 0;
	while (j <strlen(s[i]))
	{
		 
		if (ft_isdigit(s[i][j]) == 1)
		j++;
		else
		{
			printf("ERROR WITDH IS NOT NUM");
			free(s);
			exit(1);
		}
	}
}


void	checkResolutionparam(int check, char **s)
{
	if(check != 0)
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
	param.g_width  = atoi(s[1]);
	if(atoi(s[2]) > 1440)
	param.g_height = 1440;
	else
	param.g_height = atoi(s[2]);
	free (s);
}
void init(void)
{
	g_cord.x = (TITLESIZE * param.j) + TITLESIZE/ 2;
	g_cord.y = (TITLESIZE * param.i) + TITLESIZE/ 2;
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
	g_walltexture = (int *) malloc(sizeof(int) * texturewidth *  textureheight);
	TEXTUREANALYSE();

}

int main()
{

	read_line();
	init();
	init_sprite();
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, param.g_width, param.g_height, "mlx_abdel");
	img.img = mlx_new_image(g_mlx_ptr, param.g_width, param.g_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	loadtexture();
	mlx_hook(g_win_ptr,  2, 0, key_press, &g_cord);
	mlx_loop_hook(g_mlx_ptr,move_player, &g_cord);   
	mlx_hook(g_win_ptr, 3, 0, key_release, &g_cord);
	mlx_loop(g_mlx_ptr);
}
