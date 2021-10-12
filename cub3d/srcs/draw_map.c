#include "../cub3d.h"



int g_map[MAP_NUM_COLS][MAP_NUM_ROWS] = {\
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1},\
		{1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},\
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},\
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},\
	};

void	rect(player *game, int i, int j)
{
	int tile_x;
	int	tile_y;

	tile_x = i * TILE_SIZE;
	tile_y = j * TILE_SIZE;
	i = tile_x;
	while (i < tile_x + TILE_SIZE - 1)
	{
		j = tile_y;
		while (j < tile_y + TILE_SIZE - 1)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, j++, 0xffffff);
		}
		i++;
	}
}

void	draw_map(player *game)
{
	int i;
	int j;
	int tile_x;
	int tile_y;
	
	i = 0;
	while (i < MAP_NUM_ROWS){
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			if (g_map[i][j] == 1){
				rect(game, j, i);
			}
			j++;
		}
		i++;
	}
}