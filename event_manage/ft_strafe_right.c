/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strafe_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:58:45 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 12:06:07 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_strafe_right_x(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->plane->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->plane->x * param->settings->movement) + coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->plane->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->plane->x * param->settings->movement) + coll))]
		!= '1')
		param->vectors->pos->x += (param->vectors->plane->x
		* param->settings->movement);
}

void		ft_strafe_right_y(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y +
		(param->vectors->plane->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->plane->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->plane->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->plane->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1')
		param->vectors->pos->y += (param->vectors->plane->y
		* param->settings->movement);
}

void		ft_strafe_right(t_param *param, double coll)
{
	ft_strafe_right_x(param, coll);
	ft_strafe_right_y(param, coll);
}
