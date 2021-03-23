/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 09:29:32 by lodovico         ###   ########.fr       */
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
		write(2, "Error:\nwrong .cub configuration\n", 32);
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

	if (argc != 3 && argc != 2)
		return (1);
	if (!(param = ft_start(argv[1])))
		return (2);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 7))
			ft_bmp(param);
		ft_close(param);
	}
	mlx_hook(param->win, 3, 1L << 1, ft_key_release, param);
	mlx_hook(param->win, 2, 1L << 0, ft_key_press, param);
	mlx_hook(param->win, 17, 0L, ft_close, param);
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	mlx_loop(param->mlx);
	return (0);
}
