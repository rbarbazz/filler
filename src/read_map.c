/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:03:12 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/19 23:34:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**read_map(void)
{
	char	**map;
	char	*line;
	int		i;
	t_fill	*fill;

	fill = get_fill();
	i = 0;
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	if (!(map = (char**)ft_memalloc(sizeof(char*) * fill->size_map.y + 1)))
		return (NULL);
	while (i < fill->size_map.y)
	{
		get_next_line(STDIN_FILENO, &line);
		map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	map[i] = NULL;
	return (map);
}
