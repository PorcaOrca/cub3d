/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/16 09:54:15 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
	i_x = 0;
	while (i_x < winX)
	{
		trgb = c_trgb;
		i_y = 0;
		while (i_y < winY)
		{
			if (i_y > (winY / 2))
				trgb = f_trgb;
			ft_img_pixel_put(param->img, i_x, i_y, trgb);
			i_y++;
		}
		i_x++;
	}
	ft_img_wall(param);
	ft_sprite(param);
}
