/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:02 by radib             #+#    #+#             */
/*   Updated: 2025/07/08 16:37:38 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

//il me faut une fonction pour calculer la position de l'objet a poser

//et une autre qui calcule la taille des objets que je dois poser
int	renderimage(t_map **m, int *coords)
{
	int				y;
	int				x;
	static int		i;

	y = coords[0];
	x = coords [1];
	if (!i)
		(*m)->im = malloc(sizeof(void *) * ((*m)->nbr_ligns * (*m)->nbr_cols));
	if (!(*m)->im)
		return (0);
	if ((*m)->mp[y][x] == 'P')
		(*m)->im[i] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/p.xpm", &(*m)->w, &(*m)->h);
	if ((*m)->mp[y][x] == 'C')
		(*m)->im[i] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/c.xpm", &(*m)->w, &(*m)->h);
	if ((*m)->mp[y][x] == '1')
		(*m)->im[i] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/w.xpm", &(*m)->w, &(*m)->h);
	if ((*m)->mp[y][x] == '0')
		(*m)->im[i] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/g.xpm", &(*m)->w, &(*m)->h);
	if ((*m)->mp[y][x] == 'E')
		(*m)->im[i] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/e.xpm", &(*m)->w, &(*m)->h);
	mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[i], x * (*m)->w, y * (*m)->h);
	i++;
	return (1);
}

void	imagesize(t_map *m)
{
	m->h = m->total_h / m->nbr_ligns;
	m->w = m->total_w / m->nbr_cols;
}

int	render(t_map **m)
{
	int		coords[2];

	coords[0] = 0;
	while (coords[0] < (*m)->nbr_ligns)
	{
		coords[1] = 0;
		while (coords[1] <= (*m)->nbr_cols)
		{
			renderimage(m, coords);
			coords[1]++;
		}
		coords[0]++;
	}
	return (1);
}
