/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:01:03 by rafilipe          #+#    #+#             */
/*   Updated: 2023/07/20 19:04:44 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error(char *str, t_program *game)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit_game(game);
}

void	check_nl(char *mapstr, t_program *game)
{
	if ((ft_strnstr(mapstr, "\n\n", ft_strlen(mapstr)) != 0))
	{
		free(mapstr);
		error("Map File not valid\n", game);
	}
}
