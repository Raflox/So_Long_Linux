/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:46:52 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/29 16:13:48 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	counter(t_program *game)
{
	char	*counter;

	counter = ft_itoa(game->moves);
	write(1, counter, ft_strlen(counter));
	write(1, " \r", 2);
	free(counter);
}

int	str_srch(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	get_coord(t_map *map, t_coord *axis, char token)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->matrix[i][j] == token)
			{
				axis->row = i;
				axis->len = j;
			}
			j++;
		}
		i++;
	}
}

char	**matrix_cpy(char **src, int rows)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (rows + 1));
	while (i < rows)
	{
		temp[i] = ft_strdup(src[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
