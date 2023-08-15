/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:50:14 by rafilipe          #+#    #+#             */
/*   Updated: 2023/07/20 18:38:17 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_img(t_program game, void *img, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win, img, x * 32, y * 32);
}

void	draw_imgs(t_program game)
{
	int		i;
	int		j;

	i = 0;
	while (game.map.matrix[i])
	{
		j = 0;
		while (game.map.matrix[i][j])
		{
			if (game.map.matrix[i][j] == '1')
				put_img(game, game.img->wall, j, i);
			if (game.map.matrix[i][j] == '0')
				put_img(game, game.img->blank, j, i);
			if (game.map.matrix[i][j] == 'P')
				put_img(game, game.img->player, j, i);
			if (game.map.matrix[i][j] == 'E' && game.map.collectible)
				put_img(game, game.img->exit_false, j, i);
			if (game.map.matrix[i][j] == 'E' && !game.map.collectible)
				put_img(game, game.img->exit_true, j, i);
			if (game.map.matrix[i][j] == 'C')
				put_img(game, game.img->collectible, j, i);
			j++;
		}
		i++;
	}
}

void	*new_file_img(char *path, t_program game)
{
	void	*img;

	img = mlx_xpm_file_to_image(game.mlx, path, &game.map.w, &game.map.h);
	if (!img)
		error(path, &game);
	return (img);
}

void	get_imgs(t_program game)
{
	game.img->blank = new_file_img("./textures/blank.xpm", game);
	game.img->wall = new_file_img("./textures/wall.xpm", game);
	game.img->collectible = new_file_img("./textures/collectible.xpm", game);
	game.img->exit_false = new_file_img("./textures/closed_exit.xpm", game);
	game.img->exit_true = new_file_img("./textures/exit.xpm", game);
	game.img->player = new_file_img("./textures/player_down.xpm", game);
}
