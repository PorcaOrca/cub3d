/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:51:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:55:20 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_param_clean(t_param *param)
{
	if (param->vectors)
	{
		if (param->vectors->dir)
			free(param->vectors->dir);
		if (param->vectors->pos)
			free(param->vectors->pos);
		if (param->vectors->plane)
			free(param->vectors->plane);
		free(param->vectors);
	}
	if (param->settings)
		free(param->settings);
	if (param->wall_data)
		free(param->wall_data);
	if (param->common_data)
		free(param->common_data);
	if (param->sprite_data)
		free(param->sprite_data);
	if (param->texture)
		free(param->texture);
}
