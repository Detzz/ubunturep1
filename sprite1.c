
#include "cub3d.h"

float	deg(float x)
{
	return ((180 / M_PI) * x);
}

void	function_readingmaptogivespritecount(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = -1;
		while (line[i][++j])
			if (line[i][j] == '2')
			{
				g_spritecount++;
			}
		i++;
	}
}

void	init_sprite(void)
{
	int	i;
	int	j;
	int	k;
	int	w;
	int	h;

	k = 0;
	i = -1;
	h = 64;
	w = 64;
	g_sp = malloc(sizeof(g_param) * (g_spritecount + 1));
	while (++i < param.num_rows && (j = -1) && (k < g_spritecount))
	{
		while (++j < param.num_col && (k < g_spritecount))
			if (param.s5[i][j] == '2')
			{
				g_sp[k].x = (float)((j + 0.5) * 64);
				g_sp[k].y = (float)((i + 0.5) * 64);
				g_sp[k].distance = sqrtf(((g_sp[k].x) - g_cord.x) * ((g_sp[k].x)
					- g_cord.x) + ((g_sp[k].y) - g_cord.y) *
						((g_sp[k].y) - g_cord.y));
				k++;
			}
	}
}

void	to_sort(void)
{
	int		i;
	int		j;
	g_param	tmp;

	i = 0;
	while (i < g_spritecount - 1)
	{
		j = i;
		while (j < g_spritecount - 1)
		{
			if (g_sp[j].distance < g_sp[j + 1].distance)
			{
				tmp = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	to_sprite(void)
{
	float	angle;
	int		k;

	k = -1;
	to_sort();
	angle = 0;
	while (++k < g_spritecount)
	{
		g_sp[k].distance = sqrtf(((g_sp[k].x) - g_cord.x) * ((g_sp[k].x)
					- g_cord.x) + ((g_sp[k].y) - g_cord.y)
						* ((g_sp[k].y) - g_cord.y));
		angle = atan2f(g_sp[k].y - g_cord.y, g_sp[k].x - g_cord.x);
		while (angle - g_cord.rotationangle > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_cord.rotationangle < -M_PI)
			angle += 2 * M_PI;
		g_sp[k].size = (float)((param.g_width / g_sp[k].distance) * 64);
		g_sp[k].yof = (float)(param.g_height / 2 - g_sp[k].size / 2);
		g_sp[k].xof = (float)(((deg(angle) - deg(g_cord.rotationangle))
						* param.g_width)
				/ 64 + ((param.g_width / 2) - (int)g_sp[k].size / 2));
		draw_sprite(k);
	}
}

void	draw_sprite(int id)
{
	int		i;
	int		j;
	int		c;
	int		*l9alwa;
	float	size;

	i = -1;
	size = g_sp[id].size;
	l9alwa = (int*)tex.data[4];
	while (++i < size - 1 && (j = -1))
	{
		if (g_sp[id].xof + i <= 0 || g_sp[id].xof + i > param.g_width - 1)
			continue ;
		if (g_rays[(int)(g_sp[id].xof + i)].distance <= g_sp[id].distance)
			continue ;
		while (++j < size - 1)
		{
			if (g_sp[id].yof + j <= 0 || g_sp[id].yof + j > param.g_height - 1)
				continue ;
			c = l9alwa[(int)((64) *
			(64 * j / (int)size) + (64 * i / (int)size))];
			if (c != l9alwa[0])
				my_mlx_pixel_put(&img, i + g_sp[id].xof, j + g_sp[id].yof, c);
		}
	}
}
