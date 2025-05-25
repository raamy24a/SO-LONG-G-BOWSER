/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:02 by radib             #+#    #+#             */
/*   Updated: 2025/05/25 19:01:39 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

void	render(void *mlx_ptr, void *win_ptr, int x, int y)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffaeb9);
}
