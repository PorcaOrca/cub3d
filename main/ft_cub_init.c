/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:57:41 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 11:18:26 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_temp_init(t_temp *temp)
{
	temp->sprite_q = 0;
	temp->floor_color = 0xFFFFFFFF;
	temp->ceiling_color = 0xFFFFFFFF;
	temp->t_dirX = 0;
	temp->t_dirY = 0;
	temp->t_planeX = 0;
	temp->t_planeY = 0;
	temp->texture1 = NULL;
	temp->texture2 = NULL;
	temp->texture3 = NULL;
	temp->texture4 = NULL;
	temp->txt_sprite = NULL;
	temp->position[0] = 0;
	temp->position[1] = 0;
	temp->width = 0;
	temp->height = 0;
	temp->temp_map = NULL;
	temp->error = 0;
}

int		ft_valid_cub(t_temp *temp)
{
	if ((unsigned int)temp->floor_color == 0xFFFFFFFF ||
		(unsigned int)temp->ceiling_color == 0xFFFFFFFF ||
		temp->texture1 == NULL ||
		temp->texture2 == NULL ||
		temp->texture3 == NULL ||
		temp->texture4 == NULL ||
		temp->txt_sprite == NULL ||
		temp->position[0] == 0 ||
		temp->position[1] == 0 ||
		temp->width == 0 ||
		temp->height == 0 ||
		temp->temp_map == NULL ||
		temp->error > 0)
		return (0);
	return (1);
}

void	ft_clean(t_temp *temp)
{
	if (temp->texture1)
		free(temp->texture1);
	if (temp->texture2)
		free(temp->texture2);
	if (temp->texture3)
		free(temp->texture3);
	if (temp->texture4)
		free(temp->texture4);
	if (temp->txt_sprite)
		free(temp->txt_sprite);
	if (temp->temp_map)
		ft_free_matrix(temp->temp_map);
}

char	*ft_element_parse(t_temp *temp, int fd)
{
	int		ret;
	char	*str;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &str);
		if (ret < 0)
		{
			close(fd);
			return (NULL);
		}
		ft_element_select(temp, str);
		if (*str == '1')
			break ;
		free(str);
	}
	return (str);
}

int		ft_cub_init(t_temp *temp, char *mapfile)
{
	int		fd;
	char	*str;

	ft_temp_init(temp);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (0);
	if ((str = ft_element_parse(temp, fd)))
		temp->temp_map = ft_map(temp, fd, str);
	close(fd);
	if (!ft_valid_cub(temp))
	{
		ft_clean(temp);
		return (0);
	}
	return (1);
}
