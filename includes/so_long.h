/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:16:22 by armhakob          #+#    #+#             */
/*   Updated: 2023/06/12 21:00:39 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "../Libft/libft.h"

typedef struct s_game
{
	void	*start;
	void	*finish;
	void	*wall;
	void	*coin;
	void	*floor;
	void	*mlx;
	void	*win;
	int		wid;
	int		hei;
	int		w_field;
	int		h_field;
	char	**map;
	int		x;
	int		y;
	int		moves;
}					t_game;

void	ft_visualization(t_game *gm);
void	ft_image(t_game *gm);
void	move_left(t_game *gm);
void	move_right(t_game *gm);
void	move_up(t_game *gm);
void	move_down(t_game *gm);
void	exit_game(void);
int		handle_key_press(int keycode, t_game *gm);
void	init_image(t_game *gm);
void	player_pos(t_game *gm);
void	player_pos(t_game *gm);
void	check_border(t_game *gm);
void	check_rectangular_coins(t_game *gm);
void	check_symbol(t_game *gm);
int		check_coin(char **map);
int		is_path_exists(char **map, int x, int y);
void	check_path(char *str, t_game *gm);
int		loop_hook(t_game *gm);
void	fill(char **probnik, t_game *gm, int x, int y);
void	check_ff(char *res, t_game *gm);
void	animation(t_game *gm);

#endif
