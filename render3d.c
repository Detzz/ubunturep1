#include"cub3d.h"

void	renderhelper2(int i, int j)
{
	while (j < g_render.wallbotpixel)
	{
		g_render.distancefromtop = j + (g_render.wallstripheight / 2)
			- (param.g_height / 2);
		g_render.Textureoffsety = g_render.distancefromtop *
			((float)textureheight / g_render.wallstripheight);
		if (g_rays[i].facingupdown == 1 && g_rays[i].washithorizontal == 1)
			g_render.Color = tex.data[0][(textureheight *
				g_render.Textureoffsety) + g_render.Textureoffsetx];
		if (g_rays[i].facingupdown == 0 && g_rays[i].washithorizontal == 1)
			g_render.Color = tex.data[1][(textureheight *
				g_render.Textureoffsety) + g_render.Textureoffsetx];
		if (g_rays[i].washithorizontal == 0 && g_rays[i].facingrightleft == 1)
			g_render.Color = tex.data[3][(textureheight *
				g_render.Textureoffsety) + g_render.Textureoffsetx];
		if (g_rays[i].washithorizontal == 0 && g_rays[i].facingrightleft == 0)
			g_render.Color = tex.data[2][(textureheight
				* g_render.Textureoffsety) + g_render.Textureoffsetx];
		my_mlx_pixel_put(&img, i * WALLSTRIPWIDTH, j, g_render.Color);
		j++;
	}
}

void	renderhelper1(int i, int j)
{
	j = 0;
	j = g_render.walltoppixel;
	if (g_rays[i].washitvertical == 1)
		g_render.Textureoffsetx = (int)g_rays[i].wallhity % TITLESIZE;
	else
		g_render.Textureoffsetx = (int)g_rays[i].wallhitx % TITLESIZE;
	renderhelper2(i, j);
}

void	rendring(int i)
{
	drawrect(i * WALLSTRIPWIDTH, 0, WALLSTRIPWIDTH, param.g_height -
			g_render.walltoppixel, param.Ceillingcolor);
	drawrect(i *
			WALLSTRIPWIDTH, g_render.wallbotpixel, WALLSTRIPWIDTH,
			param.g_height - g_render.wallbotpixel, param.Florcolor);
}

void	render3dprojectwalls(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < param.g_width)
	{
		g_render.raydistance =
		get_distance(g_cord.x, g_cord.y, g_rays[i].wallhitx, g_rays[i].wallhity)
		* cos(g_rays[i].rayangle - g_cord.rotationangle);
		g_render.distanceProjectpllane = (param.g_width / 2)
			/ tan(FOVANGLE / 2);
		g_render.wallstripheight = (TITLESIZE / g_render.raydistance) *
								g_render.distanceProjectpllane;
		g_render.walltoppixel = (param.g_height / 2) -
								(g_render.wallstripheight / 2);
		g_render.walltoppixel = (g_render.walltoppixel < 0) ? 0 :
								g_render.walltoppixel;
		g_render.wallbotpixel = (param.g_height / 2) +
								(g_render.wallstripheight / 2);
		g_render.wallbotpixel = (g_render.wallbotpixel > param.g_height) ?
								param.g_height : g_render.wallbotpixel;
		rendring(i);
		renderhelper1(i, j);
	}
	to_sprite();
}
