/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:03:12 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 09:24:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*case_100(void)
{
	char	map[10605];
	char	*line;
	int		i;

	i = 101;
	ft_bzero(map, 10605);
	while (i-- > 0)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcat(map, line);
		ft_strcat(map, "\n");
		ft_strdel(&line);
	}
	return (ft_strdup(map));
}

char	*case_24(void)
{
	char	map[1151];
	char	*line;
	int		i;

	i = 25;
	ft_bzero(map, 1151);
	while (i-- > 0)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcat(map, line);
		ft_strcat(map, "\n");
		ft_strdel(&line);
	}
	return (ft_strdup(map));
}

char	*case_15(void)
{
	char	map[370];
	char	*line;
	int		i;

	i = 16;
	ft_bzero(map, 370);
	while (i-- > 0)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcat(map, line);
		ft_strcat(map, "\n");
		ft_strdel(&line);
	}
	return (ft_strdup(map));
}