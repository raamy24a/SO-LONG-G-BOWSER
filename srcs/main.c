/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:00:54 by radib             #+#    #+#             */
/*   Updated: 2025/07/10 14:36:06 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	cleanup(t_map *m)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(m->m_ptr, m->im[i]);
		i++;
	}
	mlx_clear_window(m->m_ptr, m->w_ptr);
	// mlx_destroy_display(m->m_ptr);
	free(m->m_ptr);
	exit(0);
}

int	handle_key(int key, t_map *m)
{
	if (key == 65307)
		cleanup(m);
	if (key == 65363 || key == 65361 || key == 65362 || key == 65364
		|| key == 119 || key == 97 || key == 115 || key == 100)
		moving(m, key);
	return (0);
}

int	main(void)
{
	t_map	*m;

	m = malloc (sizeof (t_map));
	if (!parsing(&m))
		return (0);
	m->c_possessed = 0;
	m->m_ptr = mlx_init();
	m->total_w = 50 * (m->nbr_cols + 1);
	m->total_h = 50 * (m->nbr_ligns);
	m->nbr_of_moves = 0;
	m->w_ptr = mlx_new_window(m->m_ptr,
			m->total_w, m->total_h, "So_long");
	if (render(&m) != 1)
		return (printf("error"));
	mlx_key_hook(m->w_ptr, handle_key, m);
	mlx_loop(m->m_ptr);
	return (0);
}
// ESC	65307
// W	119
// A	97
// S	115
// D	100
// UP	65362
// DOWN	65364
// LEFT	65361
// RIGHT	65363
