/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:07:12 by rafilipe          #+#    #+#             */
/*   Updated: 2023/07/20 18:55:39 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_program *game)
{
	if (game->init)
	{
		free_map(game->map.matrix);
		free_map(game->map.temp);
		mlx_destroy_image(game->mlx, game->img->blank);
		mlx_destroy_image(game->mlx, game->img->collectible);
		mlx_destroy_image(game->mlx, game->img->exit_false);
		mlx_destroy_image(game->mlx, game->img->exit_true);
		mlx_destroy_image(game->mlx, game->img->player);
		mlx_destroy_image(game->mlx, game->img->wall);
		free(game->img);
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	is_game_over(t_program *game)
{
	if (!game->map.collectible)
		exit_game(game);
}

int	read_keys(int key_pressed, t_program *game)
{
	if (key_pressed == ESC)
		exit_game(game);
	else if (key_pressed == W_KEY)
		move_backforth(game, -1);
	else if (key_pressed == A_KEY)
		move_sides(game, -1);
	else if (key_pressed == S_KEY)
		move_backforth(game, 1);
	else if (key_pressed == D_KEY)
		move_sides(game, 1);
	return (0);
}
