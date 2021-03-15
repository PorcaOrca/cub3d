/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/15 11:35:04 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

t_param	*ft_start(char *str)
{
	t_param		*param;
	t_temp		*temp_cub;
	
	temp_cub = (t_temp *)malloc(sizeof(t_temp));
	if (!temp_cub)
		return (NULL);
	if (!ft_cub_init(temp_cub, str))
	{
		free(temp_cub);
		write(1, "wrong .cub configuration", 24);
		return (NULL);
	}
	if (!(param = ft_init(temp_cub)))
	{
		ft_clean(temp_cub);
		return (NULL);
	}
	free(temp_cub);
	return (param);
}

int		main(int argc, char *argv[])
{
	t_param		*param;

	if (!(param = ft_start(argv[1])) && argc != 2)
	{
		//error handling
		return (1);
	}
	mlx_hook(param->win, 3, 1L << 1, ft_key_release, param);
	mlx_hook(param->win, 2, 1L << 0, ft_key_press, param);
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	if(param->mlx)
		mlx_loop(param->mlx);
	ft_close(param);
}
