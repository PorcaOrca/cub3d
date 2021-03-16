/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:21 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/16 10:37:04 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <math.h>

void		ft_forward(t_param *param, double coll)
{
	if (Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) + coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) + coll))]
		!= '1')
		posX += (dirX * movspeed);
	if (Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX - coll)]
		!= '1' &&
		Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX - coll)]
		!= '1')
		posY += (dirY * movspeed);
}

void		ft_backward(t_param *param, double coll)
{
	if (Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) + coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) + coll))]
		!= '1')
		posX -= dirX * movspeed;
	if (Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX - coll)]
		!= '1' &&
		Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX - coll)]
		!= '1')
		posY -= dirY * movspeed;
}

void		ft_strafe_right(t_param *param, double coll)
{
	if (Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) + coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) + coll))]
		!= '1')
		posX += (planeX * movspeed);
	if (Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX - coll)]
		!= '1' &&
		Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX - coll)]
		!= '1')
		posY += (planeY * movspeed);
}

void		ft_strafe_left(t_param *param, double coll)
{
	if (Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) + coll))]
		!= '1' &&
		Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) - coll))]
		!= '1' &&
		Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) + coll))]
		!= '1')
		posX -= (planeX * movspeed);
	if (Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX - coll)]
		!= '1' &&
		Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX + coll)]
		!= '1' &&
		Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX - coll)]
		!= '1')
		posY -= (planeY * movspeed);
}

void		ft_rotate_right(t_param *param)
{
	double		tempdirX;
	double		tempplaneX;

	tempdirX = dirX;
	tempplaneX = planeX;
	dirX = (tempdirX * cos(-rotspeed)) - (dirY * sin(-rotspeed));
	dirY = (tempdirX * sin(-rotspeed)) + (dirY * cos(-rotspeed));
	planeX = (tempplaneX * cos(-rotspeed)) - (planeY * sin(-rotspeed));
	planeY = (tempplaneX * sin(-rotspeed)) + (planeY * cos(-rotspeed));
}

void		ft_rotate_left(t_param *param)
{
	double		tempdirX;
	double		tempplaneX;
	
	tempdirX = dirX;
	tempplaneX = planeX;
	dirX = (dirX * cos(rotspeed)) - (dirY * sin(rotspeed));
	dirY = (tempdirX * sin(rotspeed)) + (dirY * cos(rotspeed));
	planeX = (planeX * cos(rotspeed)) - (planeY * sin(rotspeed));
	planeY = (tempplaneX * sin(rotspeed)) + (planeY * cos(rotspeed));
}

void		ft_movement(t_param *param)
{
	double		coll;

	coll = 0.1;
	if (param->keys->mv_up)
		ft_forward(param, coll);
	if (param->keys->mv_right)
		ft_strafe_right(param, coll);
	if (param->keys->mv_left)
		ft_strafe_left(param, coll);
	if (param->keys->mv_down)
		ft_backward(param, coll);
	if (param->keys->rt_right)
		ft_rotate_right(param);
	if (param->keys->rt_left)
		ft_rotate_left(param);
}
