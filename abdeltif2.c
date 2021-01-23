
#include "cub3d.h"

unsigned	long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < param.g_width && y >= 0 && y < param.g_height)
	{
		dst = data->addr + (y * data->line_length +
			x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int		haswallat(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	mapgridindexx = floor(x / TITLESIZE);
	mapgridindexy = floor(y / TITLESIZE);
	if (mapgridindexy < 0 || mapgridindexy >= param.num_rows ||
			mapgridindexx < 0 || mapgridindexx >= param.num_col)
		return (0);
	if (param.s5[mapgridindexy][mapgridindexx] != '1')
		return (0);
	return (1);
}

int		key_release(int key)
{
	if (key == 13)
		g_cord.walkdirection = 0;
	else if (key == 1)
		g_cord.walkdirection = 0;
	else if (key == 123)
		g_cord.turndirection = 0;
	else if (key == 124)
		g_cord.turndirection = 0;
	return (0);
}

int		key_press(int key)
{
	if (key == 13)
		g_cord.walkdirection = 1;
	else if (key == 1)
		g_cord.walkdirection = -1;
	else if (key == 123)
		g_cord.turndirection = -1;
	else if (key == 124)
		g_cord.turndirection = 1;
	else if (key == 53)
		exit(1);
	return (0);
}

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

int		rayfacingupdown(float ray)
{
	if (ray > 0 && ray < M_PI)
		return (0);
	else
		return (1);
}

int		rayfacingrightleft(float ray)
{
	if (ray < (0.5 * M_PI) || ray > (1.5 * M_PI))
		return (1);
	else
		return (0);
}

float	newray(float ray)
{
	ray = fmod(ray, (2 * M_PI));
	if (ray < 0)
	{
		ray = (2 * M_PI) + ray;
	}
	return (ray);
}

int		move_player(void *taram)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;
	t_cord	*g_cord;

	g_cord = (t_cord *)taram;
	mlx_clear_window(g_mlx_ptr, g_win_ptr);
	g_cord->rotationangle += (g_cord->turndirection * g_cord->rotationspeed);
	movestep = g_cord->walkdirection * g_cord->movespeed;
	newplayerx = g_cord->x + cos(g_cord->rotationangle) * movestep;
	newplayery = g_cord->y + sin(g_cord->rotationangle) * movestep;
	if (hasWallAt(newplayerx, newplayery) == 0)
	{
		g_cord->x = newplayerx;
		g_cord->y = newplayery;
	}
	g_rays = malloc(sizeof(t_rays) * (param.g_width + 1));
	castalleays();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, img.img, 0, 0);
	return (0);
}
