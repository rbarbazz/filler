/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:15:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/27 14:36:23 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_position(t_coord next)
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
			if (fill->piece[yy][xx] == '*' && (next.y + yy > fill->size_map.y - 1 || next.x + xx > fill->size_map.x - 1 || fill->plateau[next.y + yy][next.x + xx] == fill->advers || fill->plateau[next.y + yy][next.x + xx] == fill->advers + 32))
				return (0);
			else if (fill->piece[yy][xx] == '*' && (fill->plateau[next.y + yy][next.x + xx] == fill->player || fill->plateau[next.y + yy][next.x + xx] == fill->player + 32))
				test++;
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
	fill->next.x = 0;
	fill->next.y = 0;
	while (fill->next.y < fill->size_map.y)
	{
		fill->next.x = 0;
		while (fill->next.x < fill->size_map.x)
		{
			if (test_position(fill->next) == 1)
				return (0);
			fill->next.x++;
		}
		fill->next.y++;
	}
	return (1);
}