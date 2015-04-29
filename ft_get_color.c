#include "fdf.h"


uint32_t	ft_get_color3(int z, t_env *e)
{
	if (z < 0 && e->color_set == 3)
		return(0x0054E5);
	if (z == 0 && e->color_set == 3)
		return(0x0096E1);
	if (z > 0 && z <= 5 && e->color_set == 3)
		return (0x00D6DD);
	if (z > 5 && z <= 10 && e->color_set == 3)
		return (0x00D99F);
	if (z > 10 && z <= 15 && e->color_set == 3)
		return (0x00D55C);
	if (z > 15 && z <= 20 && e->color_set == 3)
		return (0x00D21C);
	if (z > 20 && z <= 25 && e->color_set == 3)
		return (0x98C600);
	if (z > 25 && e->color_set == 3)
		return (0xBF7900);
	return (0xFF0000);	
} // HSV reverse.

uint32_t	ft_get_color2(int z, t_env *e)
{
	if (z < 0 && e->color_set == 2)
		return(0x71ABD8);
	if (z == 0 && e->color_set == 2)
		return(0xF5F4F2);
	if (z > 0 && z <= 5 && e->color_set == 2)
		return (0xACD0A5);
	if (z > 5 && z <= 10 && e->color_set == 2)
		return (0xA8C68F);
	if (z > 10 && z <= 15 && e->color_set == 2)
		return (0xEFEBC0);
	if (z > 15 && z <= 20 && e->color_set == 2)
		return (0xCAB982);
	if (z > 20 && z <= 25 && e->color_set == 2)
		return (0xAA8753);
	if (z > 25 && e->color_set == 2)
		return (0xCAC3B8);
	return (ft_get_color3(z, e));
} // HSV gradient.

uint32_t	ft_get_color(int z, t_env *e)
{
	if (z < 0 && e->color_set == 1)
		return(0x0054E5);
	if (z == 0 && e->color_set == 1)
		return(0x000FE1);
	if (z > 0 && z <= 5 && e->color_set == 1)
		return (0x3300DD);
	if (z > 5 && z <= 10 && e->color_set == 1)
		return (0x7400D9);
	if (z > 10 && z <= 15 && e->color_set == 1)
		return (0xB200D5);
	if (z > 15 && z <= 20 && e->color_set == 1)
		return (0xD200B5);
	if (z > 20 && z <= 25 && e->color_set == 1)
		return (0xCE200B5);
	if (z > 25 && e->color_set == 1)
		return (0xC240000);
	return(ft_get_color2(z, e));
} //carto gradient.
