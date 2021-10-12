/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:47:13 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/01 15:51:01 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int		hor_intersec(double angle, int pos_x, int pos_y)
{
	int	facedown;
	int faceright;
	int xstep;
	int	ystep;
	int xintercept;
	int yintercept;
	int touchx;
	int touchy;

	angle = norm_angle(angle);
	facedown = angle > 0 && angle < M_PI ? 1 : 0;
	faceright = angle > (3 * (M_PI / 2)) || angle < M_PI / 2 ? 1 : 0;
	yintercept = (int)(floor(pos_y / TILE_SIZE) * TILE_SIZE);
	yintercept += !facedown ? 0 : TILE_SIZE;
	xintercept = pos_x + (yintercept - pos_y) / tan(angle);
	xstep = TILE_SIZE / tan(angle);
	xstep *= (xstep < 0 && !facedown) ? -1 : 1;
	xstep *= (!faceright && xstep > 0) ? -1 : 1;
	ystep = TILE_SIZE;
	ystep *= !facedown ? -1 : 1;
	if (!facedown)
		touchy = yintercept - 1;
	touchy = yintercept;
	touchx = xintercept;
	while (touchx < WINDOW_WIDTH && touchx > 0 && touchy < WINDOW_HEIGT && touchy > 0)
	{
		if (has_wall_at(touchx, touchy) || has_wall_at(touchx - 1, touchy - 1))
			return ((int)sqrt(pow(pos_x - touchx, 2) + pow(pos_y - touchy, 2)));
		touchx += xstep;
		touchy += ystep;
	}
	return (0);
}

int		ver_intersec(double angle, int pos_x, int pos_y)
{
	int	facedown;
	int faceright;
	int xstep;
	int	ystep;
	int xintercept;
	int yintercept;
	int touchx;
	int touchy;

	angle = norm_angle(angle);
	facedown = angle > 0 && angle < M_PI ? 1 : 0;
	faceright = angle > (3 * (M_PI / 2)) || angle < M_PI / 2 ? 1 : 0;
	xintercept = (int)(floor(pos_y / TILE_SIZE) * TILE_SIZE);
	xintercept += !faceright ? 0 : TILE_SIZE;
	yintercept = pos_y + (xintercept - pos_x) * tan(angle);
	ystep = TILE_SIZE * tan(angle);
	ystep *= (ystep < 0 && !facedown) ? -1 : 1;
	ystep *= (!facedown && ystep > 0) ? -1 : 1;
	xstep = TILE_SIZE;
	xstep *= !faceright ? -1 : 1;
	// if (!faceright)
	// 	touchx = xintercept - 1;
	touchy = yintercept;
	touchx = xintercept;
	while (touchx < WINDOW_WIDTH && touchx > 0 && touchy < WINDOW_HEIGT && touchy > 0)
	{
		if (has_wall_at(touchx, touchy) || has_wall_at(touchx, touchy + 1))
			return ((int)sqrt(pow(pos_x - touchx, 2) + pow(pos_y - touchy, 2)));
		touchx += xstep;
		touchy += ystep;
	}
	return (0);
}

void	fieldOfView(player *game)
{
	double	ray_angle;
	int		i;
	int		dir_x;
	int		dir_y;

	ray_angle = game->angle - (FOV_ANGLE / 2);
	while (ray_angle <= game->angle + (FOV_ANGLE / 2))
	{
		i = 0;
		
		while (i < ver_intersec(ray_angle, game->pos_x, game->pos_y))
		{
			dir_x = game->pos_x + i * cos(ray_angle);
			dir_y = game->pos_y + i * sin(ray_angle);
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, dir_x, dir_y, 0xffff00);
			i++;
		}
		ray_angle += FOV_ANGLE / ((int)NUM_RAYS);
	}
}

int		deal_key(int key, void *conn)
{
	int	i;
	int	j;

	player *game;
	game = (player *)conn;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(conn);
	if ((key <= RIGHT && key >= LEFT) || key == UP)
		move(key, game);
	else if (key == ROTATION_RIGHT)
		retate(game, 1);
	else if (key == ROTATION_LEFT)
		retate(game, -1);
	i = (game->pos_x) - 2;
	fieldOfView(game);
	while (i <= (game->pos_x) + 2)
	{
		j = (game->pos_y) - 2;
		while (j <= (game->pos_y) + 2)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, j, 0xff0000);
			j++;
		}
		i++;
	}
	retate(game, 0);
	return (0);
}

int main()
{
	player	*conn = malloc(sizeof(player));
	
	conn->mlx_ptr = mlx_init();
	conn->win_ptr = mlx_new_window(conn->mlx_ptr, WINDOW_HEIGT, WINDOW_WIDTH, "mlx 42");
	conn->pos_x = WINDOW_WIDTH / 2;
	conn->pos_y = WINDOW_HEIGT / 2;
	conn->direction = 'E';
	conn->first_frame = 1;
	conn->angle = M_PI / 2;
	mlx_hook(conn->win_ptr, 2, 0, deal_key, conn);
	mlx_loop(conn->mlx_ptr);
	free(conn);
	return (0);
}
