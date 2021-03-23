/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:29:25 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:05:22 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

t_img	*ft_img_init(t_param *param)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->ptr = mlx_new_image(param->mlx, param->settings->window_size_x, param->settings->window_size_y);
	img->addr = mlx_get_data_addr(img->ptr, &img->bxp,
									&img->sizel, &img->endian);
	return (img);
}
