/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:56:25 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/01 15:52:22 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx_mms_20200219/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LEFT 			0
#define RIGHT 			2
#define UP 				13
#define DOWN 			1
#define	SPEED			4
#define	ROTATION_RIGHT	124
#define	ROTATION_LEFT	123
#define ROTATION_SPEED	M_PI/32
#define	MAP_NUM_COLS	13
#define	MAP_NUM_ROWS	13
#define	TILE_SIZE		30
#define	WINDOW_HEIGT	MAP_NUM_ROWS * TILE_SIZE
#define	WINDOW_WIDTH	MAP_NUM_COLS * TILE_SIZE
#define	FOV_ANGLE		M_PI / 3
#define	WALL_STRIP_WIDTH	1
#define NUM_RAYS		WINDOW_WIDTH / WALL_STRIP_WIDTH

// cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit -g
// cc -I minilibx_mms_20200219 main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit

typedef struct  player{
	void        *mlx_ptr;
	void        *win_ptr;
	int         pos_x;
	int         pos_y;
	char		direction;
	int			first_frame;
	double		angle;
}	player;


int		has_wall_at(int new_x, int new_y);
double	norm_angle(double angle);
void	draw_map(player *game);
void	move(int key, player *game);
void	retate(player *game, int sence);

#endif