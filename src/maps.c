/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:03:12 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/28 13:53:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**case_100(void)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	if (!(map = (char**)ft_memalloc(sizeof(char*) * 101)))
		return (NULL);
	while (i < 100)
	{
		get_next_line(STDIN_FILENO, &line);
		map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**case_24(void)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	if (!(map = (char**)ft_memalloc(sizeof(char*) * 25)))
		return (NULL);
	while (i < 24)
	{
		get_next_line(STDIN_FILENO, &line);
		map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**case_15(void)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	if (!(map = (char**)ft_memalloc(sizeof(char*) * 16)))
		return (NULL);
	while (i < 15)
	{
		get_next_line(STDIN_FILENO, &line);
		map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	map[i] = NULL;
	return (map);
}
