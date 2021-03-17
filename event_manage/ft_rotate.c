/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:13:15 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 10:13:39 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_rotate_right(t_param *param)
{
	double		tempdirx;
	double		tempplanex;

	tempdirx = dirX;
	tempplanex = planeX;
	dirX = (tempdirx * cos(-rotspeed)) - (dirY * sin(-rotspeed));
	dirY = (tempdirx * sin(-rotspeed)) + (dirY * cos(-rotspeed));
	planeX = (tempplanex * cos(-rotspeed)) - (planeY * sin(-rotspeed));
	planeY = (tempplanex * sin(-rotspeed)) + (planeY * cos(-rotspeed));
}

void		ft_rotate_left(t_param *param)
{
	double		tempdirx;
	double		tempplanex;

	tempdirx = dirX;
	tempplanex = planeX;
	dirX = (dirX * cos(rotspeed)) - (dirY * sin(rotspeed));
	dirY = (tempdirx * sin(rotspeed)) + (dirY * cos(rotspeed));
	planeX = (planeX * cos(rotspeed)) - (planeY * sin(rotspeed));
	planeY = (tempplanex * sin(rotspeed)) + (planeY * cos(rotspeed));
}
