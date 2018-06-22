/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:15:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:14 by rbarbazz         ###   ########.fr       */
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
			else if (fill->piece[yy][xx] == '*' && fill->plateau[coord_next.y + yy][coord_next.x + xx] != '.')
				return (0);
			xx++;
		}
		yy++;
	}
	return (test);
}

int			place_piece(void)
{
	t_fill	*fill;

	fill = get_fill();
	fill->coord_next.x = 0;
	fill->coord_next.y = 0;
	while (fill->coord_next.y < fill->size_map.y)
	{
		fill->coord_next.x = 0;
		while (fill->coord_next.x < fill->size_map.x)
		{
			if (test_position(fill->coord_next) == 1)
				return (0);
			fill->coord_next.x++;
		}
		fill->coord_next.y++;
	}
	return (1);
}