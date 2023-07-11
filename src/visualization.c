/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:29:02 by armhakob          #+#    #+#             */
/*   Updated: 2023/06/12 21:01:23 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game *gm)
{
	gm->start = mlx_xpm_file_to_image(gm->mlx, \
		"img/player0.xpm", &gm->wid, &gm->hei);
	gm->finish = mlx_xpm_file_to_image(gm->mlx, \
		"img/exit.xpm", &gm->wid, &gm->hei);
	gm->wall = mlx_xpm_file_to_image(gm->mlx, \
		"img/wall.xpm", &gm->wid, &gm->hei);
	gm->coin = mlx_xpm_file_to_image(gm->mlx, \
		"img/coin2.xpm", &gm->wid, &gm->hei);
	gm->floor = mlx_xpm_file_to_image(gm->mlx, \
		"img/black.xpm", &gm->wid, &gm->hei);
	gm->moves = 0;
}

void	ft_image(t_game *gm)
{
	int	i;
	int	j;

	i = 0;
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			if (gm->map[i][j] == '1')
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->wall, j * 64, i * 64);
			if (gm->map[i][j] == 'P')
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->start, j * 64, i * 64);
			if (gm->map[i][j] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->coin, j * 64, i * 64);
			if (gm->map[i][j] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->finish, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	handle_key_press(int keycode, t_game *gm)
{
	player_pos(gm);
	if (keycode == 13 && gm->map[gm->x - 1][gm->y] != '1')
		move_up(gm);
	else if (keycode == 1 && gm->map[gm->x + 1][gm->y] != '1')
		move_down(gm);
	else if (keycode == 0 && gm->map[gm->x][gm->y - 1] != '1')
		move_left(gm);
	else if (keycode == 2 && gm->map[gm->x][gm->y + 1] != '1')
		move_right(gm);
	else if (keycode == 53)
		exit_game();
	mlx_clear_window(gm->mlx, gm->win);
	ft_image(gm);
	return (0);
}

int	handle_close_window(t_game *gm)
{
	mlx_destroy_window(gm->mlx, gm->win);
	exit_game();
	return (0);
}

void	ft_visualization(t_game *gm)
{
	int		i;

	i = 0;
	gm->w_field = 64 * ft_strlen(gm->map[0]);
	while (gm->map[i])
		i++;
	gm->h_field = 64 * i;
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->w_field, \
		gm->h_field, "so_long");
	init_image(gm);
	ft_image(gm);
	mlx_hook(gm->win, 2, 0, handle_key_press, gm);
	mlx_hook(gm->win, 17, 0, handle_close_window, gm);
	mlx_loop_hook(gm->mlx, &loop_hook, gm);
	mlx_loop(gm->mlx);
}
