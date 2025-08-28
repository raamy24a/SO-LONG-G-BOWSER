/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:03:09 by radib             #+#    #+#             */
/*   Updated: 2025/07/22 14:13:35 by radib            ###   ########.fr       */
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
	void	*m_ptr;
	void	*w_ptr;
	int		nbr_ligns;
	int		nbr_cols;
	int		c;
	int		nbr_of_moves;
	int		c_copy;
	int		c_possessed;
	int		c_left;
	int		*p;
	int		e;
	int		total_w;
	int		total_h;
	int		w;
	int		h;
	void	**im;
}				t_map;

typedef struct queue
{
	int	arr[500][2];
	int	head;
	int	tail;
}			t_queue;

int		render(t_map **m);
char	*get_next_line(int fd);
int		parsing(t_map **m);
size_t	ft_strlen(const char *str);
void	moving(t_map *m, int key);
int		len_no_n(char *line);
int		movetile(t_map **m, int *coords, int *newcoords);
int		ft_putnbr(int n);
int		ft_put_unsigned(unsigned int decimal);
int		ft_putstr(char *s);
int		ft_printf(const char *format_str, ...);
int		cleanup_exit(t_map *m);
void	map_clean(t_map *m);

#endif
