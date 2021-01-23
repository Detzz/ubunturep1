#include "cub3d.h"

float	get_distance(float x0, float y0, float x, float y)
{
	return (sqrt(((x - x0) * (x - x0)) + ((y - y0) * (y - y0))));
}

void	textureanalyse(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < texturewidth)
	{
		y = 0;
		while (y < textureheight)
		{
			g_walltexture[(texturewidth * y) + x] =
			((x % 8 == 0) && (y % 8 == 0)) ? 0xFF0000 : 0xFFFFFF;
			y++;
		}
		x++;
	}
}

void	loadtexture(void)
{
	int	i;
	int	j;
	int	w;
	int	count;
	int	h;

	count = 0;
	while (count < 5)
	{
		tex.img = mlx_xpm_file_to_image(g_mlx_ptr, tex.file[count], &i, &j);
		tex.data[count] = (unsigned int *)
				mlx_get_data_addr(tex.img, &i, &j, &i);
		count++;
	}
}

void	drawrect(float x, float y, float width, float heigh, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < heigh)
	{
		my_mlx_pixel_put(&img, x, y, color);
		j++;
		y++;
	}
}
