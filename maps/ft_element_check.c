/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:42:46 by lspazzin          #+#    #+#             */
/*   Updated: 2021/03/25 12:41:27 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_element_support(t_temp *temp, char *str)
{
	if (!ft_strncmp("SO", str, 2))
	{
		if (temp->texture4)
			temp->error++;
		else
			temp->texture4 = ft_txt_wall(str);
	}
	else if (*str == 'S')
	{
		if (temp->sprite)
			temp->error++;
		else
			temp->sprite = ft_txt_wall(str);
	}
}

void		ft_element_wall(t_temp *temp, char *str)
{
	if (!ft_strncmp("WE", str, 2))
	{
		if (temp->texture1)
			temp->error++;
		else
			temp->texture1 = ft_txt_wall(str);
	}
	else if (!ft_strncmp("NO", str, 2))
	{
		if (temp->texture2)
			temp->error++;
		else
			temp->texture2 = ft_txt_wall(str);
	}
	else if (!ft_strncmp("EA", str, 2))
	{
		if (temp->texture3)
			temp->error++;
		else
			temp->texture3 = ft_txt_wall(str);
	}
}

void		ft_element_data(t_temp *temp, char *str)
{
	if (*str == 'R')
	{
		if (temp->width || temp->height)
			temp->error++;
		else
			ft_resolution(temp, str);
	}
	else if (*str == 'F')
	{
		if ((unsigned int)temp->floor_color != 0xFFFFFFFF)
			temp->error++;
		else
			temp->floor_color = ft_background(str);
	}
	else if (*str == 'C')
	{
		if ((unsigned int)temp->ceiling_color != 0xFFFFFFFF)
			temp->error++;
		else
			temp->ceiling_color = ft_background(str);
	}
}

void		ft_element_select(t_temp *temp, char *str)
{
	if (!ft_strncmp("WE", str, 2) ||
		!ft_strncmp("NO", str, 2) || !ft_strncmp("EA", str, 2))
		ft_element_wall(temp, str);
	else if (*str == 'C' || *str == 'F' || *str == 'R')
		ft_element_data(temp, str);
	else if (*str == 'S' || !ft_strncmp("SO", str, 2))
		ft_element_support(temp, str);
	else if (*str != '\0')
	{
		temp->error++;
	}
}
