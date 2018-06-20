/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:25:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 22:48:32 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**read_piece(t_coord *size_piece)
{
	char	**piece;
	char	*line;
	int		i;

	i = 0;
	if (!(piece = (char**)ft_memalloc(sizeof(char*) * (size_piece->x + 1))))
		return (NULL);
	while (i < size_piece->x)
	{
		get_next_line(STDIN_FILENO, &line);
		piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	piece[i] = NULL;
	return (piece);
}

char		**get_piece(void)
{
	char	*line;
	char	**size;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	size = ft_strsplit_whitespace(line);
	fill->size_piece.x = ft_atoi(size[1]);
	fill->size_piece.y = ft_atoi(size[2]);
	return (read_piece(&fill->size_piece));
}

char		**get_map(void)
{
	char	*line;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "15"))
	{
		fill->size_map.x = 17;
		fill->size_map.y = 15;
		ft_strdel(&line);
		return (case_15());
	}
	else if (ft_strstr(line, "24"))
	{
		fill->size_map.x = 40;
		fill->size_map.y = 24;
		ft_strdel(&line);
		return (case_24());
	}
	fill->size_map.x = 99;
	fill->size_map.y = 100;
	ft_strdel(&line);
	return (case_100());
}

char			get_p_number(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strchr(line, '1'))
	{
		ft_strdel(&line);
		return ('O');
	}
	ft_strdel(&line);
	return ('X');
}