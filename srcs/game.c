/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:37 by radib             #+#    #+#             */
/*   Updated: 2025/07/08 15:10:54 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

// void	move_right(t_map *m)
// {
// 	if (m->mp[m->p[0]][m->p[1] + 1] != '1')
// 	{
// 		if (m->mp[m->p[0]][m->p[1] + 1] == 'C')
// 			m->c_possessed++;
// 		if (m->mp[m->p[0]][m->p[1] + 1] != 'E')
// 			render()
// 	}
// }
// void	move_left(t_map *m)
// {
// 	if (m->mp[m->p[0]][m->p[1] - 1] != '1')
// 	{
// 		if (m->mp[m->p[0]][m->p[1] + 1] == 'C')
// 			m->c_possessed++;
// 		if (m->mp[m->p[0]][m->p[1] - 1] != 'E')
// 			render()
// 	}
// }
// void	move_up(t_map *m)
// {
// 	if (m->mp[m->p[0] - 1][m->p[1]] != '1')
// 	{
// 		if (m->mp[m->p[0]][m->p[1] + 1] == 'C')
// 			m->c_possessed++;
// 		if (m->mp[m->p[0] - 1][m->p[1]] != 'E')
// 			render()
// 	}
// }
// void	move_down(t_map *m)
// {
// 	if (m->mp[m->p[0] + 1][m->p[1]] != '1')
// 	{
// 		if (m->mp[m->p[0]][m->p[1] + 1] == 'C')
// 			m->c_possessed++;
// 		if (m->mp[m->p[0] + 1][m->p[1]] != 'E')
// 			render()
// 	}
// }

// void	moving(t_map *m, int key)
// {
// 	if (key == 65363 || key == 100)
// 		move_right(m);
// 	else if (key == 65361 || key == 97)
// 		move_left(m);
// 	else if (key == 65362 || key == 119)
// 		move_up(m);
// 	else if (key == 65364 || key == 115)
// 		move_down(m);
// }