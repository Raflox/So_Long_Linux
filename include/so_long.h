/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/07/20 19:04:49 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* MACROS */
# define TRUE 1
# define FALSE 0
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

/* STRUCTS */
typedef struct s_coord {
	int	row;
	int	len;
}	t_coord;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit_true;
	void	*exit_false;
	void	*collectible;
	void	*blank;
}	t_img;

typedef struct s_map {
	char	**matrix;
	char	**temp;
	int		h;
	int		w;
	int		collectible;
	int		over;
	t_coord	player;
}	t_map;

typedef struct s_program {
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	*img;
	int		moves;
	int		init;
}	t_program;

/**** SRCS *****/

// Error
void	error(char *str, t_program *game);
void	free_map(char **map);
void	check_nl(char *mapstr, t_program *game);

// Checkers
int		check_ext(char *infile, t_program *game);
int		check_args(int ac, char **av, t_program *game);

// Map Setup
char	**get_map(char *infile, t_program *game);
int		map_setup(char **matrix, t_map *map, t_program *game);
int		has_solution(t_map *map, t_program *game);

// Window
int		read_keys(int key_pressed, t_program *game);
int		exit_game(t_program *game);
void	is_game_over(t_program *game);

// Auxiliary
int		str_srch(char *s, char c);
void	get_coord(t_map *map, t_coord *axis, char token);
char	**matrix_cpy(char **src, int row);
void	counter(t_program *game);

// Images
void	draw_imgs(t_program game);
void	get_imgs(t_program game);
void	*new_file_img(char *path, t_program game);

// Moves
void	move_sides(t_program *game, int x_move);
void	move_backforth(t_program *game, int x_move);
void	move_w(t_program *game);
void	move_a(t_program *game);
void	move_s(t_program *game);
void	move_d(t_program *game);

/* DEGUG --> DELETE LATER */
void	matrix_print(char **matrix);

#endif