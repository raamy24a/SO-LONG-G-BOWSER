/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:59:19 by radib             #+#    #+#             */
/*   Updated: 2025/06/20 17:05:08 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"
#include "unistd.h"

int		len_no_n(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
void	mapping_map_cpy(t_map *m)
{
	char	*currentline;
	int		fd;
	int		i;

	m->map_cpy = malloc (sizeof (char *) * m->nbr_ligns);
	fd = open ("maps/defaultmap.ber", O_RDONLY);
	i = 0;
	currentline = get_next_line(fd);
	m->nbr_cols = (len_no_n(currentline) - 1);
	while (currentline)
	{
		if (m->nbr_cols != (int)(len_no_n(currentline) - 1))
		{
			m->map_cpy = NULL;
			return ;
		}
		m->map_cpy[i] = currentline;
		currentline = get_next_line(fd);
		i++;
	}
}

void	queue_add(t_map *m, t_queue *queue, int y, int x)
{
	m->map_cpy[y][x] = '2';
	queue->arr[queue->tail][0] = y;
	queue->arr[queue->tail][1] = x;
	queue->tail++;
}

void	queue_can_find(t_map *m, t_queue *queue)
{
	int	x;
	int	y;

	queue->arr[0][0] = m->p[0];
	queue->arr[0][1] = m->p[1];
	while (queue->head < queue->tail)
	{
		y = queue->arr[queue->head][0];
		x = queue->arr[queue->head][1];
		if (m->map_cpy[y + 1][x] != '1' && m->map_cpy[y + 1][x] != '2')
			queue_add(m, queue, y + 1, x);
		if (m->map_cpy[y - 1][x] != '1' && m->map_cpy[y - 1][x] != '2')
			queue_add(m, queue, y - 1, x);
		if (m->map_cpy[y][x + 1] != '1' && m->map_cpy[y][x + 1] != '2')
			queue_add(m, queue, y, x + 1);
		if (m->map_cpy[y][x - 1] != '1' && m->map_cpy[y][x - 1] != '2')
			queue_add(m, queue, y, x - 1);
		queue->head++;
	}
}
int	is_solvable(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->nbr_ligns)
	{
		x = 0;
		while (m->map_cpy[y][x])
		{
			if (m->map_cpy[y][x] == '0' || m->map_cpy[y][x] == '2'
				|| m->map_cpy[y][x] == '1' || m->map_cpy[y][x] == '\n')
					;
			else
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
int	bfs(t_map *m)
{
	t_queue	*queue;

	queue = malloc(sizeof (t_queue));
	queue->head = 0;
	queue->tail = 1;
	queue_can_find(m, queue);
	if (is_solvable(m))
		return (1);
	return (0);
}

void	mapping_map(t_map *m)
{
	char	*currentline;
	int		fd;
	int		i;

	m->mp = malloc (sizeof (char *) * m->nbr_ligns);
	fd = open ("maps/defaultmap.ber", O_RDONLY);
	i = 0;
	currentline = get_next_line(fd);
	m->nbr_cols = (len_no_n(currentline) - 1);
	while (currentline)
	{
		if (m->nbr_cols != (int)(len_no_n(currentline) - 1))
		{
			m->mp = NULL;
			return ;
		}
		m->mp[i] = currentline;
		currentline = get_next_line(fd);
		i++;
	}
}

int	is_wall(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < m->nbr_cols && m->mp[0][j] == '1'
		&& m->mp[m->nbr_ligns - 1][j] == '1')
		j++;
	if ((m->mp[0][j] && m->mp[0][j] != '1'))
		return (0);
	i = 0;
	while (i < m->nbr_ligns)
	{
		if (m->mp[i][0] != '1'
			|| m->mp[i][m->nbr_cols] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_good(int y, int x, t_map *m)
{
	while (y < m->nbr_ligns)
	{
		x = 0;
		while (m->mp[y][x])
		{
			if (m->mp[y][x] == '0' || m->mp[y][x] == '1' || m->mp[y][x] == '\n')
				;
			else if (m->mp[y][x] == 'E')
				m->e++;
			else if (m->mp[y][x] == 'P')
			{
				m->p[0] = y;
				m->p[1] = x;
			}
			else if (m->mp[y][x] == 'C')
				m->c++;
			else
				return (0);
			x++;
		}
		y++;
	}
	if (m->e == 1 && m->p[0] != 0 && m->c > 0)
		return (1);
	return (0);
}

int	parsing(t_map *m)
{
	int		fd;

	fd = open ("maps/defaultmap.ber", O_RDONLY);
	if (!m->p)
		return (0);
	m->e = 0;
	m->p[0] = 0;
	m->c = 0;
	while (get_next_line(fd))
		m->nbr_ligns++;
	mapping_map(m);
	mapping_map_cpy(m);
	m->c_copy = m->c;
	if (m->mp == NULL)
		return (0);
	if (!is_wall(m))
		return (printf("not a good wall"));
	if (!is_good(0, 0, m))
		return (printf("not a good number of C or P or E"));
	if (!bfs(m))
		return (printf("no path\n"));
	else
		return (1);
}
