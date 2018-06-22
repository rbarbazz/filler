/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:15:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/22 18:16:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_position(t_coord coord_next)
{
	int	test;
	int	xx;
	int	yy;
	t_fill	*fill;

	fill = get_fill();
	xx = 0;
	yy = 0;
	test = 0;
	while (yy < fill->size_piece.y)
	{
		xx = 0;
		while (xx < fill->size_piece.x)
		{
			if (fill->piece[yy][xx] == '*' && (fill->plateau[coord_next.y + yy][coord_next.x + xx] == fill->player || fill->plateau[coord_next.y + yy][coord_next.x + xx] == fill->player + 32))
				test++;
			if (fill->piece[yy][xx] == '*' && (fill->plateau[coord_next.y + yy][coord_next.x + xx] == fill->advers || fill->plateau[coord_next.y + yy][coord_next.x + xx] == fill->advers + 32))
				return (0);
			xx++;
		}
		yy++;
	}
	return (test);
}

t_coord			place_piece(void)
{
	t_coord	coord_next;
	t_fill	*fill;

	fill = get_fill();
	coord_next.x = 0;
	coord_next.y = 0;
	while (coord_next.y < fill->size_map.y)
	{
		coord_next.x = 0;
		while (coord_next.x < fill->size_map.x)
		{
			if (test_position(coord_next) == 1)
				return (coord_next);
			coord_next.x++;
		}
		coord_next.y++;
	}
	return (coord_next);
}