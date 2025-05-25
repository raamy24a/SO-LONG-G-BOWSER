/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:00:54 by radib             #+#    #+#             */
/*   Updated: 2025/05/25 19:13:11 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	x = 200;
	y = 400;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 600, "Fortnite");
	render(mlx_ptr, win_ptr, x, y);
	mlx_loop(mlx_ptr);
	return (0);
}
