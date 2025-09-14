/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:20:28 by abdael-m          #+#    #+#             */
/*   Updated: 2025/09/14 17:17:58 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_player_colliding(t_globaldata *t,
	double currently_x, double currently_y)
{
	double	buffer;

	buffer = 1;
	return (ft_iswall(t, currently_x + buffer, currently_y + buffer)
		|| ft_iswall(t, currently_x - buffer, currently_y + buffer)
		|| ft_iswall(t, currently_x + buffer, currently_y - buffer)
		|| ft_iswall(t, currently_x - buffer, currently_y - buffer));
}

static void	setposition(double new_x, double new_y, t_globaldata *t)
{
	if (!is_player_colliding(t, new_x, new_y))
	{
		t->player.px = new_x;
		t->player.py = new_y;
	}
}

static void	setfov(double angler, t_globaldata *t)
{
	t->player.angler = angler;
	if (t->player.angler < 0)
		t->player.angler += 2 * PI;
	else if (t->player.angler > 2 * PI)
		t->player.angler -= 2 * PI;
}

void	handle_keys(t_globaldata *t)
{
	if (t->keys[0])
		setposition(t->player.px + cos(t->player.angler) * SPEED,
			t->player.py + sin(t->player.angler) * SPEED, t);
	if (t->keys[1])
		setposition(t->player.px - cos(t->player.angler) * SPEED,
			t->player.py - sin(t->player.angler) * SPEED, t);
	if (t->keys[2])
		setposition(t->player.px + cos(t->player.angler - PID2) * SPEED,
			t->player.py + sin(t->player.angler - PID2) * SPEED, t);
	if (t->keys[3])
		setposition(t->player.px + cos(t->player.angler + PID2) * SPEED,
			t->player.py + sin(t->player.angler + PID2) * SPEED, t);
	if (t->keys[4])
		setfov(t->player.angler - PI / 300, t);
	if (t->keys[5])
		setfov(t->player.angler + PI / 300, t);
}

int	pressinit(int key, t_globaldata *t)
{
	if (key == KEY_W)
		t->keys[0] = 1;
	if (key == KEY_S)
		t->keys[1] = 1;
	if (key == KEY_A)
		t->keys[2] = 1;
	if (key == KEY_D)
		t->keys[3] = 1;
	if (key == KEY_LEFT)
		t->keys[4] = 1;
	if (key == KEY_RIGHT)
		t->keys[5] = 1;
	if (key == KEY_ESC)
		exitinit(t);
	return (0);
}
