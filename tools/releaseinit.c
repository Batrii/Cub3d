/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   releaseinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:03:42 by abdael-m          #+#    #+#             */
/*   Updated: 2025/09/14 17:17:22 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_iswall(t_globaldata *t, double currently_x, double currently_y)
{
	return (t->map[(int)(currently_y / TILE_SIZE)]
		[(int)(currently_x / TILE_SIZE)] == '1');
}

int	releaseinit(int key, t_globaldata *t)
{
	if (key == KEY_W)
		t->keys[0] = 0;
	if (key == KEY_S)
		t->keys[1] = 0;
	if (key == KEY_A)
		t->keys[2] = 0;
	if (key == KEY_D)
		t->keys[3] = 0;
	if (key == KEY_LEFT)
		t->keys[4] = 0;
	if (key == KEY_RIGHT)
		t->keys[5] = 0;
	return (0);
}
