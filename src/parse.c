/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:25:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 10:10:48 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*read_piece(t_coord *size_piece)
{
	char	piece[size_piece->x * (size_piece->y + 1)];
	char	*line;
	int		i;

	i = size_piece->x;
	ft_bzero(piece, size_piece->x * (size_piece->y + 1));
	while (i-- > 0)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcat(piece, line);
		ft_strcat(piece, "\n");
		ft_strdel(&line);
	}
	return (ft_strdup(piece));
}

char		*get_piece(void)
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

char		*get_map(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "15"))
	{
		ft_strdel(&line);
		return (case_15());
	}
	else if (ft_strstr(line, "24"))
	{
		ft_strdel(&line);
		return (case_24());
	}
	ft_strdel(&line);
	return (case_100());
}

int			get_p_number(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strchr(line, '1'))
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);
}