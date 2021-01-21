#include"cub3d.h"
void    render3Dprojectwalls()
{
	float raydistance;
	float distanceProjectpllane;
	float wallstripheight;
	int walltoppixel;
	int wallbotpixel;
	int Textureoffsetx;
	int Textureoffsety;    
	int distancefromtop;
	unsigned int Color;
	int i;
	i = 0;
	int j;

	while (i < param.g_width)
	{
		j = 0;
		raydistance = get_distance(g_cord.x,g_cord.y,g_rays[i].wallhitx,g_rays[i].wallhity) * cos(g_rays[i].rayangle -  g_cord.rotationangle);
		distanceProjectpllane = (param.g_width/ 2) / tan(FOVANGLE / 2);
		wallstripheight = (TITLESIZE / raydistance) * distanceProjectpllane;
		walltoppixel = (param.g_height / 2) - (wallstripheight / 2);
		walltoppixel = (walltoppixel < 0) ? 0: walltoppixel;
		wallbotpixel = (param.g_height / 2) + (wallstripheight / 2);
		wallbotpixel = (wallbotpixel > param.g_height) ? param.g_height:wallbotpixel;
		drawrect(i * WALLSTRIPWIDTH,0, WALLSTRIPWIDTH, param.g_height - walltoppixel, param.Ceillingcolor);
		drawrect(i * WALLSTRIPWIDTH,wallbotpixel, WALLSTRIPWIDTH, param.g_height - wallbotpixel, param.Florcolor); 
		j = walltoppixel;
		if (g_rays[i].washitvertical== 1)
			Textureoffsetx = (int)g_rays[i].wallhity % TITLESIZE;
		else 
			Textureoffsetx = (int)g_rays[i].wallhitx %TITLESIZE;
		while (j < wallbotpixel)
		{
			distancefromtop = j + (wallstripheight / 2) - (param.g_height / 2);
			Textureoffsety = distancefromtop * ((float)TEXTUREHEIGHT / wallstripheight);
			if (g_rays[i].facingupdown == 1 && g_rays[i].washithorizontal== 1)
				Color = tex.data[0][(TEXTUREWIDTH * Textureoffsety) + Textureoffsetx];
			if (g_rays[i].facingupdown == 0 && g_rays[i].washithorizontal== 1)
				Color = tex.data[1][(TEXTUREWIDTH * Textureoffsety) + Textureoffsetx];
			if (g_rays[i].washithorizontal == 0 && g_rays[i].facingrightleft == 1)
				Color = tex.data[3][(TEXTUREWIDTH * Textureoffsety) + Textureoffsetx];
			if (g_rays[i].washithorizontal == 0 && g_rays[i].facingrightleft == 0)
				Color = tex.data[2][(TEXTUREWIDTH * Textureoffsety) + Textureoffsetx];
			my_mlx_pixel_put(&img, i * WALLSTRIPWIDTH, j,Color);
			j++;
		}
		i++;
	}
	to_sprite();
}

