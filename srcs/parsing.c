/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:59:19 by radib             #+#    #+#             */
/*   Updated: 2025/06/02 16:33:15 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

int	parsing(void)
{
	int		fd;
	int		linecount;
	char	*currentline;
	char	**map;

	fd = open ("maps/defaultmap.ber", O_RDONLY);
	currentline = get_next_line(fd);
	linecount = 0;
	while (currentline != NULL)
	{
		map[linecount] = currentline;
		currentline = get_next_line(fd);
		linecount++;
	}
	if (!is_walled_off(map, linecount))
		return (0);
	return (1);
}

int	is_walled_off(char **map, int linecount)
{
	int	i;
	int	j;

	i = 0;
	while (i < linecount)
	{
		j = 0;
		if (i == 0 || i == linecount - 1)
		{
			while (map[i][j] && map[i][j] == 1)
				j++;
			if (map[i][j])
				return (0);
		}
		else
		{
			if (map[i][j] != 1)
				return (0);
			while (map[i][j + 1] != '\0')
		}
	}
	return (1);
}
// trop de probleme 
// 1 je ne sais pas comment savoir il y a combien d'elements par ligne car si
11111111111111110111111
10000000000000010111111
10000000000000010000000
11111111111111110000000
mon code futur renverrais quand meme vrai alors que c faux.