/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:32 by armhakob          #+#    #+#             */
/*   Updated: 2023/06/12 11:13:45 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_error(int x)
// {
// 	if (x)
// 	{
// 		write(2, "Error(flood fill)\n", 18);
// 		exit(1);
// 	}
// }

// void	fill(char **probnik, t_game *gm, int x, int y)
// {
// 	if (y < 1 || y >= gm->wid - 1 || x < 1 || x >= gm->hei - 1
// 		|| probnik[x][y] == '1')
// 		return ;
// 	probnik[x][y] = '1';
// 	fill(probnik, gm, x - 1, y);
// 	fill(probnik, gm, x, y - 1);
// 	fill(probnik, gm, x + 1, y);
// 	fill(probnik, gm, x, y + 1);
// }

// void	check_ff(char *res, t_game *gm)
// {
// 	int		i;
// 	char	**probnik;

// 	i = -1;
// 	probnik = ft_split(res, '\n');
// 	ft_error(!probnik);
// 	fill(probnik, gm, gm->x, gm->y);
// 	while (probnik[++i])
// 		ft_error(ft_strchr(probnik[i], 'E') || ft_strchr(probnik[i], 'C'));
// }
