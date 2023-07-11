/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:05:04 by armhakob          #+#    #+#             */
/*   Updated: 2023/06/12 21:10:01 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_norm(t_game *gm)
{
	int			i;
	int			j;

	i = -1;
	while (gm->map[++i])
	{
		j = -1;
		while (gm->map[i][++j])
		{
			if (gm->map[i][j] == 'C')
			{
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->floor, j * 64, i * 64);
				mlx_put_image_to_window(gm->mlx, gm->win, \
					gm->coin, j * 64, i * 64);
			}
		}
	}
}

void	animation(t_game *gm)
{
	static int	a;
	static int	b;

	if (a % 50 == 0)
	{
		mlx_destroy_image(gm->mlx, gm->coin);
		gm->coin = mlx_xpm_file_to_image(gm->mlx, \
		"img/coin1.xpm", &gm->wid, &gm->hei);
		anim_norm(gm);
	}
	if (b % 100 == 0)
	{
		mlx_destroy_image(gm->mlx, gm->coin);
		gm->coin = mlx_xpm_file_to_image(gm->mlx, \
		"img/coin2.xpm", &gm->wid, &gm->hei);
		anim_norm(gm);
	}
	a++;
	b++;
}
