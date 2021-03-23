/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:13:15 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 12:06:54 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_rotate_right(t_param *param)
{
	double		tempdirx;
	double		tempplanex;

	tempdirx = param->vectors->dir->x;
	tempplanex = param->vectors->plane->x;
	param->vectors->dir->x = (tempdirx * cos(-param->settings->rotation)) -
	(param->vectors->dir->y * sin(-param->settings->rotation));
	param->vectors->dir->y = (tempdirx * sin(-param->settings->rotation)) +
	(param->vectors->dir->y * cos(-param->settings->rotation));
	param->vectors->plane->x = (tempplanex * cos(-param->settings->rotation)) -
	(param->vectors->plane->y * sin(-param->settings->rotation));
	param->vectors->plane->y = (tempplanex * sin(-param->settings->rotation)) +
	(param->vectors->plane->y * cos(-param->settings->rotation));
}

void		ft_rotate_left(t_param *param)
{
	double		tempdirx;
	double		tempplanex;

	tempdirx = param->vectors->dir->x;
	tempplanex = param->vectors->plane->x;
	param->vectors->dir->x =
	(param->vectors->dir->x * cos(param->settings->rotation)) -
	(param->vectors->dir->y * sin(param->settings->rotation));
	param->vectors->dir->y =
	(tempdirx * sin(param->settings->rotation)) +
	(param->vectors->dir->y * cos(param->settings->rotation));
	param->vectors->plane->x =
	(param->vectors->plane->x * cos(param->settings->rotation)) -
	(param->vectors->plane->y * sin(param->settings->rotation));
	param->vectors->plane->y =
	(tempplanex * sin(param->settings->rotation)) +
	(param->vectors->plane->y * cos(param->settings->rotation));
}
