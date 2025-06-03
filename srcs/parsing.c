/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:59:19 by radib             #+#    #+#             */
/*   Updated: 2025/06/03 15:12:47 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

char	**mapping_map(char **map, int lcount)
{
	char	*currentline;
	int		fd;

	map = malloc (sizeof (char *) * lcount);
	fd = open ("maps/defaultmap.ber", O_RDONLY);
	lcount = 0;
	currentline = get_next_line(fd);
	while (currentline != NULL)
	{
		map[lcount] = currentline;
		currentline = get_next_line(fd);
		lcount++;
	}
	return (map);
}

int	is_wall_up_and_down(char **map, int linecount)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < linecount)
	{
		j = 0;
		if (i == 0 || i == linecount - 1)
		{
			while (map[i][j] && map[i][j] == '1')
				j++;
			if (map[i][j] && map[i][j] != '\n')
				return (0);
			if (k == 0)
				k = j;
			if (k != j)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_wall(char **map, int linecount)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (is_wall_up_and_down(map, linecount))
		return (0);
	while (i < linecount)
	{
		j = 0;
		if (i != 0 && i != linecount - 1)
		{
			while (map[i][j] && map[i][j] == '1')
				j++;
			if (map[i][j] && map[i][j] != '\n')
				return (0);
			if (k == 0)
				k = j;
			if (k != j)
				return (0);
		}
		i++;
	}
}

int	is_good(char **map, int linecount, int *i)
{
	while (i[0] && i[0] < linecount)
	{
		while (map[0][1])
		{
			if (map[0][1] == '0' || map[0][1] == '1')
			{
			}
			if (map[0][1] == 'E')
				i[2]++;
			if (map[0][1] == 'P')
				i[3]++;
			if (map[0][1] == 'C')
				i[4]++;
			else
				return (0);
			i[1]++;
		}
		i[0]++;
	}
	if (i[2] == 1 && i[3] == 1 && i[4] >= 1)
		return (1);
	else
		return (0);
}

int	parsing(void)
{
	int		lcount;
	char	**map;
	int		fd;

	fd = open ("maps/defaultmap.ber", O_RDONLY);
	lcount = 0;
	while (get_next_line(fd))
		lcount++;
	map = 0;
	map = mapping_map(map, lcount);
	if (!is_wall(map, lcount) && !is_good(map, lcount, (int []){0, 0, 0, 0, 0}))
		return (0);
	else
		return (1);
}