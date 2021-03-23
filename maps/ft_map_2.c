/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:08:14 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:41:15 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_spawn(t_temp *temp, char position)
{
	if (position == 'N')
	{
		temp->t_diry = -1;
		temp->t_planex = 0.66;
	}
	else if (position == 'S')
	{
		temp->t_diry = 1;
		temp->t_planex = -0.66;
	}
	else if (position == 'E')
	{
		temp->t_dirx = 1;
		temp->t_planey = 0.66;
	}
	else if (position == 'W')
	{
		temp->t_dirx = -1;
		temp->t_planey = -0.66;
	}
}

int			ft_limit(char **matrix, int i)
{
	int		prev;
	int		forw;
	int		curr;

	curr = ft_strlen(matrix[i]);
	if (i != 0 && matrix[i + 1] != NULL)
	{
		prev = ft_strlen(matrix[i - 1]);
		forw = ft_strlen(matrix[i + 1]);
		if (prev < curr || forw < curr)
		{
			if (prev < forw)
				return (prev);
			else
				return (forw);
		}
	}
	return (curr);
}

int			ft_char_check(char **matrix, int i, int j)
{
	if (i == 0 || matrix[i + 1] == NULL
		|| j == 0 || matrix[i][j + 1] == '\0')
	{
		if (matrix[i][j] != '1' && matrix[i][j] != ' ')
			return (0);
	}
	else if (matrix[i][j] != '1' && matrix[i][j] != ' ')
	{
		if (!ft_strchr("012NSEW", matrix[i - 1][j]) ||
			!ft_strchr("012NSEW", matrix[i + 1][j]) ||
			!ft_strchr("012NSEW", matrix[i][j + 1]) ||
			!ft_strchr("012NSEW", matrix[i][j - 1]))
			return (0);
	}
	return (1);
}

int			ft_map_check(char **matrix)
{
	int		i;
	int		j;
	int		limit;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		limit = ft_limit(matrix, i);
		while (matrix[i][j])
		{
			if (j >= limit)
			{
				if (matrix[i][j] != '1' && matrix[i][j] != ' ')
					return (0);
			}
			if (!(ft_char_check(matrix, i, j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
