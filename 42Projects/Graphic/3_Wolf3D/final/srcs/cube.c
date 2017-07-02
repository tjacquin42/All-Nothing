/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:32:42 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 16:48:50 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	create_cube(t_all *truc)
{
	if (truc->dirx < -0.5 && truc->dirx > -1 && truc->diry < 0.5 && truc->diry
			> -0.5 && truc->map[(int)truc->player_pos_x - 1]
			[(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x - 1]
			[(int)truc->player_pos_y] = truc->which;
	if (truc->dirx >= -0.5 && truc->diry < 0.5 && truc->diry > -0.5 && truc->
			map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x + 1]
			[(int)truc->player_pos_y] = truc->which;
	if (truc->diry < -0.5 && truc->diry > -1 && truc->dirx < 0.5 && truc->dirx
			> -0.5 && truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y - 1] < 15)
		truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y - 1] = truc->which;
	if (truc->diry >= -0.5 && truc->dirx < 0.5 && truc->dirx > -0.5 && truc->
			map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] < 15)
		truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y + 1] = truc->which;
}

void	destroy_cube(t_all *truc)
{
	if (truc->dirx < -0.5 && truc->dirx > -1 && truc->diry < 0.5 && truc->diry
			> -0.5 && truc->map[(int)truc->player_pos_x - 1]
			[(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x - 1][(int)truc->player_pos_y] = 0;
	if (truc->dirx >= -0.5 && truc->diry < 0.5 && truc->diry > -0.5 && truc->
			map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] = 0;
	if (truc->diry < -0.5 && truc->diry > -1 && truc->dirx < 0.5 && truc->dirx
			> -0.5 && truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y - 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y - 1] = 0;
	if (truc->diry >= -0.5 && truc->dirx < 0.5 && truc->dirx > -0.5 && truc->
			map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] = 0;
}
