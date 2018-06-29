/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:15:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/29 12:44:34 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_position(t_coord next, char **map, char **piece)
{
	int		xx;
	int		yy;
	t_fill	*fill;

	fill = get_fill();
	xx = 0;
	yy = 0;
	fill->match = 0;
	while (yy < fill->size_piece.y)
	{
		xx = 0;
		while (xx < fill->size_piece.x)
		{
			if (piece[yy][xx] == '*' && (next.y + yy > fill->size_map.y - 1 ||\
			next.x + xx > fill->size_map.x - 1 || next.y + yy < 0 || next.x +\
			xx < 0 || map[next.y + yy][next.x + xx] == fill->advers))
				return (0);
			else if (piece[yy][xx] == '*' && map[next.y + yy][next.x + xx] ==\
			fill->player)
				fill->match++;
			xx++;
		}
		yy++;
	}
	return (fill->match);
}

int				place_piece(void)
{
	t_fill	*fill;

	fill = get_fill();
	fill->next.x = -1 * fill->size_map.x;
	fill->next.y = -1 * fill->size_map.y;
	while (fill->next.y < fill->size_map.y)
	{
		fill->next.x = -1 * fill->size_map.x;
		while (fill->next.x < fill->size_map.x)
		{
			if (test_position(fill->next, fill->plateau, fill->piece) == 1)
				return (0);
			fill->next.x++;
		}
		fill->next.y++;
	}
	return (1);
}
