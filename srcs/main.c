/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:00:54 by radib             #+#    #+#             */
/*   Updated: 2025/07/14 06:19:38 by radib            ###   ########.fr       */
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
	mlx_destroy_display(m->m_ptr);
	free(m->m_ptr);
	free(m->map_cpy);
	free(m->p);
	free(m->mp);
	free(m->im);
	free(m);
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

void	init_m(t_map **m)
{
	t_map	*n;

	n = *m;
	n->c_possessed = 0;
	n->m_ptr = mlx_init();
	n->total_w = 50 * (n->nbr_cols + 1);
	n->total_h = 50 * (n->nbr_ligns);
	n->nbr_of_moves = 0;
	n->w_ptr = mlx_new_window(n->m_ptr, n->total_w, n->total_h, "So_long");
}
int	main(void)
{
	t_map	*m;

	m = malloc (sizeof (t_map));
	m->nbr_ligns = 0;
	if (!parsing(&m))
		return (0);
	init_m(&m);
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
