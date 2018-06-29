/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:25:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/29 16:43:13 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**read_piece(t_coord *size_piece)
{
	char	**piece;
	char	*line;
	int		i;

	i = 0;
	if (!(piece = (char**)ft_memalloc(sizeof(char*) * (size_piece->y + 1))))
		return (NULL);
	while (i < size_piece->y)
	{
		get_next_line(STDIN_FILENO, &line);
		piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	piece[i] = NULL;
	return (piece);
}

int			get_piece(void)
{
	char	*line;
	char	**size;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	size = ft_strsplit_whitespace(line);
	if (!ft_strstr(size[0], "Piece") || !size[1] || !size[2] ||\
	!ft_isdigit(size[1][0]) || !ft_isdigit(size[2][0]))
	{
		strstr_free(size);
		return (fill->ret = 1);
	}
	fill->size_piece.y = ft_atoi(size[1]);
	fill->size_piece.x = ft_atoi(size[2]);
	fill->piece = read_piece(&fill->size_piece);
	strstr_free(size);
	return (fill->ret);
}

int			get_map(void)
{
	char	*line;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "Plateau 15 17:") && (fill->plateau = (map_15())))
	{
		fill->size_map.x = 17;
		fill->size_map.y = 15;
	}
	else if (ft_strstr(line, "Plateau 24 40:") && (fill->plateau = (map_24())))
	{
		fill->size_map.x = 40;
		fill->size_map.y = 24;
	}
	else if (ft_strstr(line, "Plateau 100 99:") &&\
	(fill->plateau = (map_100())))
	{
		fill->size_map.x = 99;
		fill->size_map.y = 100;
	}
	else
		fill->ret = 1;
	ft_strdel(&line);
	return (fill->ret);
}

int			get_player_char(void)
{
	char	*line;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "$$$ exec p1 :"))
	{
		fill->player = 'O';
		fill->advers = 'X';
	}
	else if (ft_strstr(line, "$$$ exec p2 :"))
	{
		fill->player = 'X';
		fill->advers = 'O';
	}
	else
		fill->ret = 1;
	ft_strdel(&line);
	return (fill->ret);
}
