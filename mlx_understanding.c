/*#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int    input(int key, t_struct *param)
{
    param->futurposx = param->posx;
    param->futurposy = param->posy;
    mlx_clear_window(param->mlx_pointer, param->window);
    if (key == 65307)
        freeing(param);
    if (key == 100)
        param->futurposx += 96;
    else if (key == 97)
        param->futurposx -= 96;
    else if (key == 115)
        param->futurposy += 96;
    else if (key == 119)
        param->futurposy -= 96;
    if (key == 100)
        param->facing = 0;
    if (key == 97)
        param->facing = 1;
    check_input(param, key);
    return (0);
}

mlx_hook(general->window, 17, 0, &freeing, general);
mlx_hook(general->window, KeyPress, KeyPressMask, &input, general);
mlx_loop(general->mlx_pointer);

int    freeing(t_struct    *param)
{
    mlx_destroy_window(param->mlx_pointer, param->window);
    mlx_destroy_image(param->mlx_pointer, param->exit2.img);
    mlx_destroy_image(param->mlx_pointer, param->coll2.img);
    mlx_destroy_image(param->mlx_pointer, param->tomato.img);
    mlx_destroy_image(param->mlx_pointer, param->tapis.img);
    mlx_destroy_image(param->mlx_pointer, param->dog1.img);
    mlx_destroy_image(param->mlx_pointer, param->dog2.img);
    mlx_destroy_image(param->mlx_pointer, param->dog3.img);
    mlx_destroy_image(param->mlx_pointer, param->tonneau.img);
    mlx_destroy_image(param->mlx_pointer, param->bag.img);
    mlx_destroy_image(param->mlx_pointer, param->sol.img);
    mlx_destroy_image(param->mlx_pointer, param->exit.img);
    mlx_destroy_image(param->mlx_pointer, param->corn.img);
    mlx_destroy_image(param->mlx_pointer, param->guysprite.img);
    mlx_destroy_image(param->mlx_pointer, param->guyreverse.img);
    mlx_destroy_image(param->mlx_pointer, param->coll.img);
    mlx_destroy_display(param->mlx_pointer);
    free(param->mlx_pointer);
    ft_splitfree(param->tab);
    free(param);
    exit (0);
    return (0);
}
	mlx_loop(data.mlx); 
	mlx_destroy_window(data.mlx_win, data.mlx_win);
	mlx_destroy_display(data.mlx);
	ft_freetab(data.map);

int    input(int key, t_struct *param)
{
    param->futurposx = param->posx;
    param->futurposy = param->posy;
    mlx_clear_window(param->mlx_pointer, param->window);
    if (key == 65307)
        freeing(param);
    if (key == 100)
        param->futurposx += 96;
    else if (key == 97)
        param->futurposx -= 96;
    else if (key == 115)
        param->futurposy += 96;
    else if (key == 119)
        param->futurposy -= 96;
    if (key == 100)
        param->facing = 0;
    if (key == 97)
        param->facing = 1;
    check_input(param, key);
    return (0);
}*/