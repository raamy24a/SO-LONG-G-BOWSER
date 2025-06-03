/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:00:54 by radib             #+#    #+#             */
/*   Updated: 2025/06/03 14:28:22 by radib            ###   ########.fr       */
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
	// void	*mlx_ptr;
	// void	*win_ptr;
	// void	*img;
	// int		i_w;
	// int		i_h;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1000, 600, "Fortnite");
	// cleanup(mlx_ptr, win_ptr, 0);
	// img = mlx_xpm_file_to_image(mlx_ptr, "xpm/player.xpm", &i_w, &i_h);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	// mlx_key_hook(win_ptr, handle_key, NULL);
	// mlx_loop(mlx_ptr);
	printf("%d\n", parsing());
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
