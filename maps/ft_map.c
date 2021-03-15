/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:03:01 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/15 09:03:15 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_spawn(t_temp *temp, char position)
{
	if (position == 'N')
	{
		temp->t_dirY = -1;
		temp->t_planeX = 0.66;
	}
	else if (position == 'S')
	{
		temp->t_dirY = 1;
		temp->t_planeX = -0.66;
	}
	else if (position == 'E')
	{
		temp->t_dirX = 1;
		temp->t_planeY = 0.66;
	}
	else if (position == 'W')
	{
		temp->t_dirX = -1;
		temp->t_planeY = -0.66;
	}
}

int			ft_map_check(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (i == 0 || matrix[i + 1] == NULL || j == 0 || matrix[i][j + 1] == '\0')
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
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_map_fill(char **matrix, t_temp *temp, t_list *line, int map_size)
{
	int		i;
	int		j;
	t_list	*lst_temp;
	
	i = 0;
	while (i < map_size)
	{
		j = 0;
		matrix[i] = (char *)line->content;
		while (matrix[i][j])
		{
			ft_spawn(temp, matrix[i][j]);
			if (matrix[i][j] == 'W' || matrix[i][j] == 'S' || matrix[i][j] == 'E' || matrix[i][j] == 'N')
			{
				temp->position[0] = j;
				temp->position[1] = i;
			}
			if (matrix[i][j] == '2')
				temp->sprite_q++;
			j++;

		}
		lst_temp = line->next;
		free(line);
		line = lst_temp;
		i++;
	}
}

char		**ft_map(t_temp *temp, int fd, char *str)
{
	t_list		*line;
	t_list		*new;
	int			ret;
	char		**matrix;
	int			map_size;
	
	ret = 1;
	line = ft_lstnew(str);
	while (ret)
	{
		ret = get_next_line(fd, &str);
		if (ret < 0)
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
		new = ft_lstnew(str);
		ft_lstadd_back(&line, new);
	}
	close(fd);
	map_size = ft_lstsize(line);
	matrix = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (!matrix)
	{
		ft_lstclear(&line, free);
		return (NULL);
	}
	matrix[map_size] = NULL;
	ft_map_fill(matrix, temp, line, map_size);
	if (!ft_map_check(matrix))
	{
		ft_free_matrix(matrix);
		matrix = NULL;
	}
	return (matrix);
}