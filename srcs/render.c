/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:02 by radib             #+#    #+#             */
/*   Updated: 2025/06/20 16:17:38 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

//il me faut une fonction pour calculer la position de l'objet a poser

//et une autre qui calcule la taille des objets que je dois poser
int	renderimage(void *mlx_ptr, void *win_ptr, t_map *m, int *coords)
{
	void	*img;
	int		y;
	int		x;

	y = coords[0];
	x = coords [1];
	if (m->mp[y][x] == 'P')
		img = mlx_xpm_file_to_image(mlx_ptr, "xpm/player.xpm", &m->w, &m->h);
	if (m->mp[y][x] == 'C')
		img = mlx_xpm_file_to_image(mlx_ptr, "xpm/conso.xpm", &m->w, &m->h);
	if (m->mp[y][x] == '1')
		img = mlx_xpm_file_to_image(mlx_ptr, "xpm/wall.xpm", &m->w, &m->h);
	if (m->mp[y][x] == '0')
		img = mlx_xpm_file_to_image(mlx_ptr, "xpm/ground.xpm", &m->w, &m->h);
	if (m->mp[y][x] == 'E')
		img = mlx_xpm_file_to_image(mlx_ptr, "xpm/exit.xpm", &m->w, &m->h);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * m->w, y * m->h);
	return (1);
}

void	imagesize(t_map *m)
{
	m->h = m->total_h / m->nbr_ligns;
	m->w = m->total_w / m->nbr_cols;
}

int	render(void *mlx_ptr, void *win_ptr, t_map *m)
{
	int		coords[2];

	coords[0] = 0;
	while (coords[0] < m->nbr_ligns)
	{
		coords[1] = 0;
		while (coords[1] < m->)
		{
			renderimage(mlx_ptr, win_ptr, m, coords);
			coords[1]++;
		}
		coords[0]++;
	}
	return (1);
}
