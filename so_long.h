/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:09 by radib             #+#    #+#             */
/*   Updated: 2025/06/03 16:17:45 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct map_data
{
	char	**map;
	int		nbr_ligns;
	int		nbr_cols;
	int		c;
	int		p;
	int		e;
}				t_map;

void	render(void *mlx_ptr, void *win_ptr, int x, int y);
char	*get_next_line(int fd);
int		parsing(void);

#endif
