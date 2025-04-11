/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:26:48 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 15:06:12 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_long
{
	char	*ptr;
	char	*pttr;
	char	**lines;
	char	**map;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		nbline;
	int		lenline;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		move;
	int		oldmove;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*exit1;
	void	*player_r;
	void	*player_l;
	void	*player_f;
	void	*player_up;
	void	*player_down;
	void	*backgrnd;
	char	face;
	int		img_width;
	int		img_height;
}	t_long;

char	*read_map(char *file);
void	lenline(t_long *data);
void	checkchar(char **map, t_long *data);
void	checkwall(t_long *data);
void	flood_fill(int x, int y, t_long *data);
void	fillitems(t_long *data);
void	img_to_window(t_long *data);
void	move_up(t_long *data);
void	move_down(t_long *data);
void	move_right(t_long *data);
void	move_left(t_long *data);
int		ft_exit(t_long *data);
int		key_hook(int keycode, t_long *data);
void	*ft_free(char **str);
void	msg_error(int i, char *msg, t_long *data);
void	destroy_img(t_long *data);
void	img_to_window(t_long *data);
void	fillitems(t_long *data);
void	move_up(t_long *data);
void	move_down(t_long *data);
void	move_right(t_long *data);
void	move_left(t_long *data);
void	check_ber(char *av, char *ber, t_long *data);

#endif