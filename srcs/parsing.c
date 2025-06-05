/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:59:19 by radib             #+#    #+#             */
/*   Updated: 2025/06/05 15:53:35 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

void	mapping_map_cpy(t_map *mapdata)
{
	char	*currentline;
	int		fd;
	int		i;

	mapdata->map_cpy = malloc (sizeof (char *) * mapdata->nbr_ligns);
	fd = open ("maps/defaultmap.ber", O_RDONLY);
	i = 0;
	currentline = get_next_line(fd);
	mapdata->nbr_cols = (ft_strlen(currentline) - 1);
	while (currentline)
	{
		if (mapdata->nbr_cols != (int)(ft_strlen(currentline) - 1))
		{
			mapdata->map_cpy = NULL;
			return ;
		}
		mapdata->map_cpy[i] = currentline;
		currentline = get_next_line(fd);
		i++;
	}
}

int	is_solved(int i, int j, t_map *mapdata)
{
	u;
}

int	bfs(t_map *mapdata)
{
	int	i;

	i = 0;
	while (is_solved == 0 && i < 10000)
	{
		i++;
	}
	if (is_solved == 1)
		return (1);
	else
		return (0);
}

void	mapping_map(t_map *mapdata)
{
	char	*currentline;
	int		fd;
	int		i;

	mapdata->map = malloc (sizeof (char *) * mapdata->nbr_ligns);
	fd = open ("maps/defaultmap.ber", O_RDONLY);
	i = 0;
	currentline = get_next_line(fd);
	mapdata->nbr_cols = (ft_strlen(currentline) - 1);
	while (currentline)
	{
		if (mapdata->nbr_cols != (int)(ft_strlen(currentline) - 1))
		{
			mapdata->map = NULL;
			return ;
		}
		mapdata->map[i] = currentline;
		currentline = get_next_line(fd);
		i++;
	}
}

int	is_wall_up_and_down(t_map *mapdata)
{
	int	j;

	j = 0;
	while (j < mapdata->nbr_cols && mapdata->map[0][j] == '1'
		&& mapdata->map[mapdata->nbr_ligns - 1][j] == '1')
		j++;
	if (mapdata->map[0][j] && mapdata->map[0][j] != '\n')
		return (0);
	return (1);
}

int	is_wall(t_map *mapdata)
{
	int	i;

	i = 0;
	if (!is_wall_up_and_down(mapdata))
		return (0);
	while (i < mapdata->nbr_ligns)
	{
		if (mapdata->map[i][0] != '1'
			|| mapdata->map[i][mapdata->nbr_cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_good(int i, int j, t_map *mapdata)
{
	while (i < mapdata->nbr_ligns)
	{
		j = 0;
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == '0' || mapdata->map[i][j] == '1'
				|| mapdata->map[i][j] == '\n')
			{
			}
			else if (mapdata->map[i][j] == 'E')
				mapdata->e++;
			else if (mapdata->map[i][j] == 'P')
				mapdata->p = mapdata->map[i][j];
			else if (mapdata->map[i][j] == 'C')
				mapdata->c++;
			else
				return (0);
			j++;
		}
		i++;
	}
	if (mapdata->e == 0 && mapdata->p && mapdata->c == 0)
		return (1);
	else
		return (0);
}

int	parsing(void)
{
	int		fd;
	t_map	*mapdata;

	fd = open ("maps/defaultmap.ber", O_RDONLY);
	mapdata = malloc (sizeof (t_map));
	while (get_next_line(fd))
		mapdata->nbr_ligns++;
	mapping_map(mapdata);
	mapping_map_cpy(mapdata);
	mapdata->c_copy = mapdata->c;
	if (mapdata->map == NULL)
		return (0);
	mapdata->p = 0;
	if (!is_wall(mapdata) || !is_good(0, 0, mapdata) || !bfs(mapdata))
		return (0);
	else
		return (1);
}
