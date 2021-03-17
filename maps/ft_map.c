/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:03:01 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 09:30:30 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_map_obj(char **matrix, int i, int j, t_temp *temp)
{
	if (matrix[i][j] == 'W' || matrix[i][j] == 'S'
		|| matrix[i][j] == 'E' || matrix[i][j] == 'N')
	{
		temp->position[0] = j;
		temp->position[1] = i;
	}
	if (matrix[i][j] == '2')
		temp->sprite_q++;
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
			ft_map_obj(matrix, i, j, temp);
			j++;
		}
		lst_temp = line->next;
		free(line);
		line = lst_temp;
		i++;
	}
}

char		**ft_lst_to_matrix(t_temp *temp, t_list *line)
{
	int		map_size;
	char	**matrix;

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

char		**ft_map(t_temp *temp, int fd, char *str)
{
	t_list		*line;
	t_list		*new;
	int			ret;

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
		if (!(new = ft_lstnew(str)))
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
		ft_lstadd_back(&line, new);
	}
	return (ft_lst_to_matrix(temp, line));
}
