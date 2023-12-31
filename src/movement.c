/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:28:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/06/12 10:28:56 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *gm)
{
	if (gm->map[gm->x - 1][gm->y] == 'E' && check_coin(gm->map))
	{
		write(1, "You win!\n", 9);
		exit(0);
	}
	if (gm->map[gm->x - 1][gm->y] != 'E')
	{
		gm->map[gm->x - 1][gm->y] = 'P';
		gm->map[gm->x][gm->y] = '0';
		gm->moves++;
	}
}

void	move_down(t_game *gm)
{
	if (gm->map[gm->x + 1][gm->y] == 'E' && check_coin(gm->map))
	{
		write(1, "You win!\n", 9);
		exit(0);
	}
	if (gm->map[gm->x + 1][gm->y] != 'E')
	{
		gm->map[gm->x + 1][gm->y] = 'P';
		gm->map[gm->x][gm->y] = '0';
		gm->moves++;
	}
}

void	move_left(t_game *gm)
{
	if (gm->map[gm->x][gm->y - 1] == 'E' && check_coin(gm->map))
	{
		write(1, "You win!\n", 9);
		exit(0);
	}
	if (gm->map[gm->x][gm->y - 1] != 'E')
	{
		gm->map[gm->x][gm->y - 1] = 'P';
		gm->map[gm->x][gm->y] = '0';
		gm->moves++;
	}
}

void	move_right(t_game *gm)
{
	if (gm->map[gm->x][gm->y + 1] == 'E' && check_coin(gm->map))
	{
		write(1, "You win!\n", 9);
		exit(0);
	}
	if (gm->map[gm->x][gm->y + 1] != 'E')
	{
		gm->map[gm->x][gm->y + 1] = 'P';
		gm->map[gm->x][gm->y] = '0';
		gm->moves++;
	}
}

void	exit_game(void)
{
	write(1, "You closed the game!\n", 21);
	exit(0);
}
