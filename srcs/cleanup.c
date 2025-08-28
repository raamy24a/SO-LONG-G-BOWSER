/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:11:25 by radib             #+#    #+#             */
/*   Updated: 2025/07/22 14:13:18 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

int	cleanup_exit(t_map *m)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(m->m_ptr, m->im[i]);
		i++;
	}
	mlx_clear_window(m->m_ptr, m->w_ptr);
	mlx_destroy_window(m->m_ptr, m->w_ptr);
	mlx_destroy_display(m->m_ptr);
	free(m->m_ptr);
	free(m->im);
	map_clean(m);
	exit(0);
}