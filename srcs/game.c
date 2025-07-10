/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:37 by radib             #+#    #+#             */
/*   Updated: 2025/07/10 14:21:02 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

void	move_right(t_map *m)
{
	if (m->mp[m->p[0]][m->p[1] + 1] != '1')
	{
		if (m->mp[m->p[0]][m->p[1] + 1] == 'C')
			m->c_possessed++;
		if (m->mp[m->p[0]][m->p[1] + 1] == 'E' && m->c_possessed == m->c)
			mlx_put_image_to_window(m->m_ptr, m->w_ptr, m->im[5], 0, 0);
		movetile(&m, (int []){m->p[0],m->p[1]}, (int []){m->p[0],(m->p[1]+ 1)});
	}
}
void	move_left(t_map *m)
{
	if (m->mp[m->p[0]][m->p[1] - 1] != '1')
	{
		if (m->mp[m->p[0]][m->p[1] - 1] == 'C')
			m->c_possessed++;
		if (m->mp[m->p[0]][m->p[1] - 1] == 'E' && m->c_possessed == m->c)
			mlx_put_image_to_window(m->m_ptr, m->w_ptr, m->im[5], 0, 0);
		movetile(&m, (int []){m->p[0],m->p[1]}, (int []){m->p[0],(m->p[1]- 1)});
	}
}
void	move_up(t_map *m)
{
	if (m->mp[m->p[0] - 1][m->p[1]] != '1')
	{
		if (m->mp[m->p[0] - 1][m->p[1]] == 'C')
			m->c_possessed++;
		if (m->mp[m->p[0] - 1][m->p[1]] == 'E' && m->c_possessed == m->c)
		{
			mlx_put_image_to_window(m->m_ptr, m->w_ptr, m->im[5], 0, 0);
		}
		movetile(&m, (int []){m->p[0],m->p[1]}, (int []){(m->p[0] - 1),m->p[1]});
	}
}
void	move_down(t_map *m)
{
	if (m->mp[m->p[0] + 1][m->p[1]] != '1')
	{
		if (m->mp[m->p[0] + 1][m->p[1]] == 'C')
			m->c_possessed++;
		if (m->mp[m->p[0] + 1][m->p[1]] == 'E' && m->c_possessed == m->c)
		{
			mlx_put_image_to_window(m->m_ptr, m->w_ptr, m->im[5], 0, 0);
		}
		movetile(&m, (int []){m->p[0],m->p[1]}, (int []){(m->p[0] + 1),m->p[1]});
	}
}

void	moving(t_map *m, int key)
{
	if (key == 65363 || key == 100)
		move_right(m);
	else if (key == 65361 || key == 97)
		move_left(m);
	else if (key == 65362 || key == 119)
		move_up(m);
	else if (key == 65364 || key == 115)
		move_down(m);
}