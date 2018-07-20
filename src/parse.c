/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:25:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/19 23:40:58 by rbarbazz         ###   ########.fr       */
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
	ft_strdel(&line);
	if (!ft_strstr(size[0], "Piece") || !size[1] || !size[2] ||\
	!ft_isdigit(size[1][0]) || !ft_isdigit(size[2][0]))
	{
		strstr_free(size);
		return (fill->ret = 1);
	}
	fill->size_piece.y = ft_atoi(size[1]);
	fill->size_piece.x = ft_atoi(size[2]);
	strstr_free(size);
	fill->piece = read_piece(&fill->size_piece);
	return (fill->ret);
}

int			get_map(void)
{
	char	*line;
	char	**split_line;
	t_fill	*fill;

	fill = get_fill();
	get_next_line(STDIN_FILENO, &line);
	split_line = ft_strsplit_whitespace(line);
	ft_strdel(&line);
	if (!split_line || !split_line[1] || !split_line[2])
		return (fill->ret = 1);
	fill->size_map.x = ft_atoi(split_line[2]);
	fill->size_map.y = ft_atoi(split_line[1]);
	strstr_free(split_line);
	fill->plateau = read_map();
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
