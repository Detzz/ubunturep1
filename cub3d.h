/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:42:49 by aali-mou          #+#    #+#             */
/*   Updated: 2021/01/09 15:45:20 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <fcntl.h> 
#include <string.h>
#include "libft.h"
# define RAD(x) (x * 180 / M_PI)
#define BUFFER_SIZE 30
//const float Fongle = 60 *( M_PI / 180);
#define TEXTUREWIDTH 64
#define TEXTUREHEIGHT 64
#define TITLESIZE  64
#define MAP_NUMS_ROWS  10
#define MAP_NUMS_COLS  10
#define WINDOW_WIDTH  (TITLESIZE  * MAP_NUMS_COLS)
#define WINDOW_HEIGHT  (TITLESIZE  * MAP_NUMS_ROWS)
#define FOVANGLE (60 * (M_PI/180))
#define WALLSTRIPWIDTH 1
#define NUMRAYS (WINDOW_WIDTH / WALLSTRIPWIDTH)
#define Minimapfac 0.2


int  g_tab[10][10];
void *g_mlx_ptr; 
void *g_win_ptr;
float  g_foundvertwallhit;
float  g_foundhortwallhit;
float g_wallhitx;
float g_wallhity;
float g_distance;
float g_RAYS[10000][10000];
float  g_washithorizontal;
float  g_washitvertical;
int *g_walltexture;


typedef struct s_player
{
	int walkdirection;
	int turndirection;
	float x;
	float y;
	float rotationangle;  
	float movespeed;
	float rotationspeed;
	float wallhorhitx;
	float wallhorhity;
	float wallverhitx;
	float wallverhity;
	float nexthorx;
	float nexthory;
	float nextverx;
	float nextvery;


} t_cord;

t_cord g_cord;

typedef struct s_rays {
	float distance;
	int washitvertical;
	int washithorizontal;
	int facingupdown;
	float rayangle;
	int facingrightleft;
	float wallhitx;
	float wallhity;
}t_rays ;
t_rays *g_rays;

void lOADTEXRURE();
void TEXTUREANALYSE(void);
int key_release(int key);
int key_press(int key);
void    printsquare(int i, int j, void *mlx_ptr, void *win_ptr);
void    draw_map();
void    draw_player(float x, float y);
int     move_player( void *taram );
void    draw_line(float x, float y, float j);
typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;
t_data  img;


void    *iiimg;
char *tp;
int     img_width;
int     img_height;
unsigned int *data;

typedef struct	s_sprite1
{
	void			*img;
	unsigned int	*data;
	char			*file;
	int				width;
	int				height;
	int				color;
}				t_sprite;
t_sprite spr;

typedef struct	s_texture
{
	void			*img;
	unsigned int	*data[5];
	char			*file[5];
	int				width;
	int				height;
	int				color;
}				t_texture;

t_texture tex;
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1, size_t i);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_calloc(size_t count, size_t size);
char	**ft_split_whitespaces(char *str);
char	**ft_split_virgules(char *str);
int resolution(char *line);
void texture(char *line);
void FLOORCOLOR(char *line);
int		ft_atoi(const char *str);
unsigned long createRGB(int r, int g, int b);
void CEILLINGCOLOR(char *line);
float newray(float ray);
void analyse_sprite(int i);
void lOADSPRITE();
typedef struct s_params
{
	int g_width;
	int g_height;
	char *texture;
	unsigned long Florcolor;
	unsigned long Ceillingcolor;
	int num_col;
	int num_rows;
	int tab[100][100];
	int i;
	int j;
	char **s5;
	int count;
} t_params;
t_params param;
int g_count;
char *s ;
void TREATMAP(char*line);
char	**ft_split(char *str, char c );
int g_spritecount;
typedef struct s_sprite
{
	float x;
	float y;
	float xof;
	float yof;
	float angle;
	float distance;
	int width;
	int heigth;
	unsigned int *data;
	float size;

} g_param;
g_param *g_sp;
void function_readingmaptogivespritecount(char **line);
int  spritesize;
void     my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	get_distance(float x0, float y0, float x, float y);
void    drawrect(float x, float y, float width, float heigh, int color);
int hasWallAt(float x, float y) ;
void    draw_line2(float x, float y,  float w , float z, int color);
int     rayfacingupdown(float ray);
int     rayfacingrightleft(float ray);
void    castalleays();
void    render3Dprojectwalls();
void sprite_function(void);
void	init_sprite(void);
float	deg(float x);
void	to_sort(void);
void	to_sprite(void);
void	draw_sprite(int id);



