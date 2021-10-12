#include "../cub3d.h"

void	retate(player *game, int sence)
{
	int	i;
	double	angle;
	int dir_x,dir_y;

	i = 0;
	if (sence != 0)
		game->angle = game->angle + ROTATION_SPEED * sence;
	while (i < 40)
	{
		dir_x =  game->pos_x + i * cos(game->angle);
		dir_y = game->pos_y + i * sin(game->angle);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, dir_x, dir_y, 0xff0000);
		i++;
	}
	game->first_frame = 0;
}