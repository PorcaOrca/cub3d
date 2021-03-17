/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:00:18 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 11:25:01 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int			ft_resolution(t_temp *temp, char *str)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	if (i != 3 || ft_strncmp(matrix[0], "R", 2))
	{
		ft_free_matrix(matrix);
		return (0);
	}
	temp->width = ft_atoi(matrix[1]);
	temp->height = ft_atoi(matrix[2]);
	ft_free_matrix(matrix);
	return (1);
}

int			ft_back_color(char *str)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**matrix;
	
	matrix = ft_split(str, ',');
	if (!matrix)
		return (0xFFFFFFFF);
	i = 0;
	while (matrix[i])
		i++;
	if (i != 3)
		return (0xFFFFFFFF);
	r = ft_atoi(matrix[0]);
	g = ft_atoi(matrix[1]);
	b = ft_atoi(matrix[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0xFFFFFFFF);
	return (ft_color(0, r, g, b));
}

int			ft_background(char *str)
{
	int		i;
	char	**matrix;
	int		color;

	matrix = ft_split(str, ' ');
	if (!matrix)
		return (0xFFFFFFFF);
	i = 0;
	while (matrix[i])
		i++;
	if (i != 2 || (ft_strncmp(matrix[0], "F", 2)
		&& ft_strncmp(matrix[0], "C", 2)))
	{
		ft_free_matrix(matrix);
		return (0xFFFFFFFF);
	}
	color = ft_back_color(matrix[1]);
	ft_free_matrix(matrix);
	return (color);
}

char		*ft_txt_wall(char *str)
{
	char	**matrix;
	char	*temp_str;
	int		i;

	i = 0;
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (NULL);
	while (matrix[i])
		i++;
	if (i != 2 || (ft_strncmp(matrix[0], "NO", 3)
				&& ft_strncmp(matrix[0], "WE", 3)
				&& ft_strncmp(matrix[0], "SO", 3)
				&& ft_strncmp(matrix[0], "EA", 3)
				&& ft_strncmp(matrix[0], "S", 2)))
	{
		ft_free_matrix(matrix);
		return (NULL);
	}
	temp_str = matrix[1];
	free(matrix[0]);
	free(matrix);
	return (temp_str);
}

void		ft_element_select(t_temp *temp, char *str)
{
	if (*str == 'R')
		ft_resolution(temp, str);
	else if (*str == 'F')
		temp->floor_color = ft_background(str);
	else if (*str == 'C')
		temp->ceiling_color = ft_background(str);
	else if (!ft_strncmp("WE", str, 2))
		temp->texture1 = ft_txt_wall(str);
	else if (!ft_strncmp("NO", str, 2))
		temp->texture2 = ft_txt_wall(str);
	else if (!ft_strncmp("EA", str, 2))
		temp->texture3 = ft_txt_wall(str);
	else if (!ft_strncmp("SO", str, 2))
		temp->texture4 = ft_txt_wall(str);
	else if (*str == 'S')
		temp->txt_sprite = ft_txt_wall(str);
	else if (*str != '\n')
	{
		temp->error++;
		debugint(temp->error);
		debugstr(str);
	}
}
