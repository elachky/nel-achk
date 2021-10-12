#include "../cub3d.h"

void	move(int key, player *game)
{
	int i;
	int j;
	double angle;
	int	new_x;
	int new_y;

	i = 0;
	j = 0;
	if (key == UP)
		angle = 0;
	else if (key == RIGHT)
		angle = M_PI / 2;
	else if (key == LEFT)
		angle = M_PI / -2;
	else if (key == DOWN)
		angle = M_PI;
	new_x = game->pos_x + SPEED * cos(game->angle + angle);
	new_y = game->pos_y + SPEED * sin(game->angle + angle);
	if (!has_wall_at(new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
}