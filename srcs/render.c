/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:02 by radib             #+#    #+#             */
/*   Updated: 2025/07/09 15:40:04 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

//il me faut une fonction pour calculer la position de l'objet a poser

//et une autre qui calcule la taille des objets que je dois poser
int	renderimages(t_map **m)
{
	int	x;

	x = 50;
	(*m)->im = malloc(sizeof(void *) * 5);
	if (!(*m)->im)
		return (0);
	(*m)->im[2] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/p.xpm", &x, &x);
	(*m)->im[4] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/c.xpm", &x, &x);
	(*m)->im[1] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/w.xpm", &x, &x);
	(*m)->im[0] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/g.xpm", &x, &x);
	(*m)->im[3] = mlx_xpm_file_to_image((*m)->m_ptr, "xpm/e.xpm", &x, &x);
	return (1);
}
void	putimages(t_map **m, int *coords)
{
	int	x;
	int	y;
	int	a;
	int	b;

	y = coords[0];
	x = coords[1];
	a = x * 50;
	b = y * 50;
	if ((*m)->mp[y][x] == 'P')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[2], a, b);
	if ((*m)->mp[y][x] == 'C')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[4], a, b);
	if ((*m)->mp[y][x] == '0')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[0], a, b);
	if ((*m)->mp[y][x] == '1')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[1], a, b);
	if ((*m)->mp[y][x] == 'E')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[3], a, b);
}
void	movetile(t_map **m, int *coords, int *newcoords)
{
	int	x;
	int	y;
	int	a;
	int	b;

	y = coords[0];
	x = coords[1];
	a = x * 50;
	b = y * 50;
	if ((*m)->mp[y][x] == 'E')
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[3], a, b);
	else
		mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[0], a, b);
	y = newcoords[0];
	x = newcoords[1];
	a = x * 50;
	b = y * 50;
	mlx_put_image_to_window((*m)->m_ptr, (*m)->w_ptr, (*m)->im[2], a, b);
}

int	render(t_map **m)
{
	renderimages(m);
	int		coords[2];

	coords[0] = 0;
	while (coords[0] < (*m)->nbr_ligns)
	{
		coords[1] = 0;
		while (coords[1] <= (*m)->nbr_cols)
		{
			putimages(m, coords);
			coords[1]++;
		}
		coords[0]++;
	}
	return (1);
}

