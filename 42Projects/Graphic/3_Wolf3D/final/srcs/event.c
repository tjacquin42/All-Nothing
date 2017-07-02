/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:29:01 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 20:31:14 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		key_input_2(int keycode, t_all *truc)
{
	if (keycode == SPRINT)
	{
		if (truc->move_speed == 0.09)
			truc->move_speed = 0.18;
		else
			truc->move_speed = 0.09;
	}
	if (keycode == 12)
	{
		truc->player_moving_up = !truc->player_moving_up;
		truc->player_moving_left = !truc->player_moving_left;
	}
	if (keycode == 14)
	{
		truc->player_moving_up = !truc->player_moving_up;
		truc->player_moving_right = !truc->player_moving_right;
	}
	return (0);
}

int		key_input(int keycode, t_all *truc)
{
	if (keycode == ECHAP)
		return (echap_key(truc));
	if (keycode == 83)
		truc->which = 1;
	else if (keycode == 84)
		truc->which = 2;
	else if (keycode == 85)
		truc->which = 3;
	else if (keycode == 86)
		truc->which = 4;
	else if (keycode == 87)
		truc->which = 5;
	else if (keycode == 88)
		truc->which = 6;
	if (keycode == UP)
		truc->player_moving_up = !truc->player_moving_up;
	else if (keycode == DOWN)
		truc->player_moving_down = !truc->player_moving_down;
	else if (keycode == LEFT)
		truc->player_moving_left = !truc->player_moving_left;
	else if (keycode == RIGHT)
		truc->player_moving_right = !truc->player_moving_right;
	return (key_input_2(keycode, truc));
}

int		mouse_input(int keycode, int x, int y, t_all *truc)
{
	x = y;
	if (keycode == 1)
		destroy_cube(truc);
	else if (keycode == 3 || keycode == 2)
		create_cube(truc);
	return (0);
}

int		loop_hook(t_all *truc)
{
	if (truc->player_moving_up != 0)
		move_up(truc);
	if (truc->player_moving_down != 0)
		move_down(truc);
	if (truc->player_moving_left != 0)
		move_left(truc);
	if (truc->player_moving_right != 0)
		move_right(truc);
	find_walls(truc);
	return (0);
}
