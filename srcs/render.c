/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:02 by radib             #+#    #+#             */
/*   Updated: 2025/06/18 13:00:24 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

//il me faut une fonction pour calculer la position de l'objet a poser

//et une autre qui calcule la taille des objets que je dois poser

int	render(void *mlx_ptr, void *win_ptr, t_map *m)
{
	void	*img;
	char	*diff_letters;
	int		i;
	int		j;

	diff_letters = "01ECP";
	i = 0;
	while(i < m->nbr_ligns)
	{
		while(m->mp[i][j])
		{
			
			j++;
		}
	}
	img = mlx_xpm_file_to_image(mlx_ptr, "xpm/player.xpm", m->w, m->h);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 300, 300);
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffaeb9);
}
