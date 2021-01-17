#include "cub3d.h"


unsigned long createRGB(int r, int g, int b)
{   
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void     my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	if (x >= 0 && x < param.g_width && y >= 0 && y < param.g_height)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int hasWallAt(float x, float y) 
{
	int mapGridIndexX = floor(x / TITLESIZE);
	int mapGridIndexY = floor(y / TITLESIZE);
	if (mapGridIndexY < 0 || mapGridIndexY >= param.num_rows ||
			mapGridIndexX < 0 || mapGridIndexX >= param.num_col)
		return (0);
	if (param.s5[mapGridIndexY][mapGridIndexX] != '1')
		return (0);
	return (1);
}

int key_release(int key)
{
	if (key == 122) // linux 122 mac 13
		g_cord.walkdirection = 0; 
	else if (key == 115) // linux 115 mac 1
		g_cord.walkdirection = 0;
	else if (key == 65361)// left // linux 65361 mac 123
		g_cord.turndirection = 0;
	else if (key == 65363)// right //linux 65363 mac 124 
		g_cord.turndirection = 0;
	return (0);
}

int key_press(int key)
{
	if (key == 122)
		g_cord.walkdirection = 1;
	else if (key == 115)
		g_cord.walkdirection = -1;
	else if (key == 65361)// left
		g_cord.turndirection = -1;
	else if (key == 65363)
	{// right
	printf("lopooo \n") ;
		g_cord.turndirection = 1;}
	else if (key == 65307) // linux 65307 mac 53
		exit(1);
	return (0);

}

int abs (int n) 
{ 
	return ( (n>0) ? n : ( n * (-1))); 
} 

void    draw_line2(float x, float y,  float w , float z, int color)
{

	int r;
	int f;
	int steps;


	r=  z - y;
	f = w - x;
	steps = abs(f) > abs(r) ? abs(f) : abs(r);
	float Xinc = f / (float) steps;
	float Yinc = r / (float) steps;
	float a = x;
	float b = y;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x += Xinc;
		y += Yinc;
	}
}

int     rayfacingupdown(float ray)
{
	if (ray > 0 && ray < M_PI)
		return(0);
	else 
		return (1);
}
int     rayfacingrightleft(float ray)
{
	if ( ray < (0.5 * M_PI) ||  ray > (1.5 * M_PI) )
		return(1);
	else 
		return (0);
}

float newray(float ray)
{

	ray = fmod(ray, (2 * M_PI));
	if (ray < 0) 
	{
		ray = (2 * M_PI ) + ray ;
	}

	return ray;
}

void    draw_line(float x, float y, float j)
{
	float x1;
	float y1;
	int steps;
	x1 = x + cos(g_cord.rotationangle) * 20;
	y1 = y + sin(g_cord.rotationangle) * 20;
	steps = sqrt(pow((x1 - x),2) + pow((y1 - y),2));
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(&img, x, y, 0xFF0000);
		x += cos(j) * 1;
		y += sin(j) * 1;
	}
}

void    draw_map()
{
	int i, j;

	i = 0;
	j = 0;
    //printf("%d num - rows")
	while (i < param.num_rows)
	{
		j = 0;
		while (j < param.num_col)
		{
			if (param.s5[i][j] == '1')
				printsquare(j, i, g_mlx_ptr, g_win_ptr);
			j++;
		}
		i++;
	}
}
void printsquare(int i, int j, void *mlx_ptr, void *win_ptr)

{
	int x = 0;
	int y = 0;
	int X = (i * TITLESIZE) ;
	int Y = (j * TITLESIZE) ;
	int z = Y;
	x = X + (TITLESIZE) ;
	y = Y + (TITLESIZE) ;
	while (X  < x)
	{
		Y= z;
		while (Y < y)
		{
			my_mlx_pixel_put(&img, X ,Y , 0x00dfff);
			Y++;
		}
		X++;
	}
}

int     move_player(void *taram)
{   
	float movestep;
	float newplayerx;
	float newplayery;
	int c;
	int j;

	t_cord *g_cord = (t_cord *)taram;
	mlx_clear_window(g_mlx_ptr, g_win_ptr);
	g_cord->rotationangle += (g_cord->turndirection * g_cord->rotationspeed);
	movestep = g_cord->walkdirection * g_cord->movespeed;
	newplayerx = g_cord->x + cos(g_cord->rotationangle) * movestep;
	newplayery = g_cord->y + sin(g_cord->rotationangle) * movestep;
	if (hasWallAt(newplayerx,newplayery) == 0)
	{
		g_cord->x = newplayerx;
		g_cord->y = newplayery;
	}
	g_rays = malloc(sizeof(t_rays) * (param.g_width + 1));
	castalleays();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, img.img, 0, 0);
	return(0);
}
