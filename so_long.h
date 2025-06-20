/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:09 by radib             #+#    #+#             */
/*   Updated: 2025/06/20 14:50:54 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct m
{
	char	**mp;
	char	**map_cpy;
	int		nbr_ligns;
	int		nbr_cols;
	int		c;
	int		c_copy;
	int		p[2];
	int		e;
	int		total_w;
	int		total_h;
	int		w;
	int		h;
}				t_map;

typedef struct queue
{
	int	arr[500][2];
	int	head;
	int	tail;
}			t_queue;

int		render(void *mlx_ptr, void *win_ptr, t_map *m);
char	*get_next_line(int fd);
int		parsing(t_map *m);
size_t	ft_strlen(const char *str);

#endif
