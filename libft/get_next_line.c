/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:29:53 by rafilipe          #+#    #+#             */
/*   Updated: 2023/08/15 14:20:42 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
		{
			while (stash[fd][i])
				stash[fd][i++] = 0;
		}
		return (NULL);
	}
	line = NULL;
	while (*(stash[fd]) || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		line = ft_join(line, stash[fd]);
		if (ft_nextclean(stash[fd]))
			break ;
	}
	return (line);
}
