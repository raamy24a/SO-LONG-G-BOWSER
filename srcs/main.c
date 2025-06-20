/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:00:54 by radib             #+#    #+#             */
/*   Updated: 2025/06/20 15:37:20 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include "../so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	cleanup(void	*mlx_ptr, void	*win_ptr, int i)
{
	static void	*mlx_ptrr;
	static void	*win_ptrr;

	if (i == 0)
	{
		mlx_ptrr = mlx_ptr;
		win_ptrr = win_ptr;
	}
	if (i == 1)
	{
		mlx_clear_window(mlx_ptrr, win_ptrr);
		mlx_destroy_display(mlx_ptrr);
		free(mlx_ptrr);
		exit(0);
	}
}

int	handle_key(int keycode, void *param)
{
	if (keycode == 65307)
		cleanup(NULL, NULL, 1);
	// if (keycode == 119)
	// 	W;
	// if (keycode == 97)
	// 	A;
	// if (keycode == 115)
	// 	S;
	// if (keycode == 100)
	// 	D;
	(void)param;
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*m;

	m = malloc (sizeof (t_map));
	m->total_w = 2000;
	m->total_h = 2000;
	if (parsing(m) != 1)
		return (printf("error"));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, m->total_w, m->total_h, "Fortnite");
	cleanup(mlx_ptr, win_ptr, 0);
	if (render(mlx_ptr, win_ptr, m) != 1)
		return (printf("error"));
	mlx_key_hook(win_ptr, handle_key, NULL);
	mlx_loop(mlx_ptr);
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
