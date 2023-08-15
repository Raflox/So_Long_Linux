/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:58:42 by rafilipe          #+#    #+#             */
/*   Updated: 2023/07/20 18:58:27 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	make_moves_ad(t_program *game, int x_move)
{
	if (game->map.matrix[game->map.player.row] \
		[game->map.player.len + x_move] == 'C')
	{
		game->map.collectible--;
		game->map.matrix[game->map.player.row][game->map.player.len] = '0';
		game->map.player.len += x_move;
		game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
	}
	else if (game->map.matrix[game->map.player.row] \
			[game->map.player.len + x_move] == '0')
	{
		game->map.matrix[game->map.player.row][game->map.player.len] = '0';
		game->map.player.len += x_move;
		game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
	}
	game->moves++;
	counter(game);
}

static void	make_moves_ws(t_program *game, int y_move)
{
	if (game->map.matrix[game->map.player.row + y_move] \
		[game->map.player.len] == 'C')
	{
		game->map.collectible--;
		game->map.matrix[game->map.player.row][game->map.player.len] = '0';
		game->map.player.row += y_move;
		game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
	}
	else if (game->map.matrix[game->map.player.row + y_move] \
			[game->map.player.len] == '0')
	{
		game->map.matrix[game->map.player.row][game->map.player.len] = '0';
		game->map.player.row += y_move;
		game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
	}
	game->moves++;
	counter(game);
}

void	move_backforth(t_program *game, int y_move)
{
	t_coord	p_pos;

	p_pos = game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	if (y_move > 0)
		game->img->player = new_file_img("./textures/player_down.xpm", *game);
	else
		game->img->player = new_file_img("./textures/player_up.xpm", *game);
	if (game->map.matrix[p_pos.row + y_move][p_pos.len] != '1'\
		&& game->map.matrix[p_pos.row + y_move][p_pos.len] != 'E')
		make_moves_ws(game, y_move);
	else if (game->map.matrix[p_pos.row + y_move][p_pos.len] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_sides(t_program *game, int x_move)
{
	t_coord	p_pos;

	p_pos = game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	if (x_move > 0)
		game->img->player = new_file_img("./textures/player_right.xpm", *game);
	else
		game->img->player = new_file_img("./textures/player_left.xpm", *game);
	if (game->map.matrix[p_pos.row][p_pos.len + x_move] != '1'\
		&& game->map.matrix[p_pos.row][p_pos.len + x_move] != 'E')
		make_moves_ad(game, x_move);
	else if (game->map.matrix[p_pos.row][p_pos.len + x_move] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}
