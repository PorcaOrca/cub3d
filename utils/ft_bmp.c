/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:11:26 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:48:46 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <sys/stat.h>

void	ft_bmp_data(t_param *param, int fd)
{
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < param->settings->window_size_y)
	{
		j = 0;
		while (j < param->settings->window_size_x)
		{
			color = ft_get_txtcolor(param->img, j, i);
			write(fd, &color, 3);
			j++;
		}
		i++;
	}
}

void	ft_set_int_char(unsigned char *str, int n)
{
	str[0] = (unsigned char)(n);
	str[1] = (unsigned char)(n >> 8);
	str[2] = (unsigned char)(n >> 16);
	str[3] = (unsigned char)(n >> 24);
}

void	write_bmp_header(int fd, int filesize, t_param *param)
{
	int				i;
	int				tmp;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_set_int_char(&header[2], filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	tmp = param->settings->window_size_x;
	ft_set_int_char(&header[18], tmp);
	tmp = param->settings->window_size_y;
	ft_set_int_char(&header[22], tmp);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
}

void	ft_bmp(t_param *param)
{
	int		fd;
	int		pad;
	int		filesize;

	pad = (4 - ((int)param->settings->window_size_x * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)param->settings->window_size_x + pad)
				* (int)param->settings->window_size_y);
	param->img = ft_img_init(param);
	ft_img_fill(param);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write_bmp_header(fd, filesize, param);
	ft_bmp_data(param, fd);
	close(fd);
	mlx_destroy_image(param->mlx, param->img->ptr);
	free(param->img);
}
