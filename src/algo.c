/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:36:18 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/30 21:20:42 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	algo_bot_right(void)
{
	t_fill	*fill;
	int		first_play;

	fill = get_fill();
	first_play = fill->size_map.y;
	if (fill->size_map.y < 20)
		first_play = 30;
	else if (fill->size_map.y > 95)
		first_play = fill->size_map.y / 2;
	if (fill->call < first_play)
		return (place_top_left());
	return (place_bot_left());
}

static int	algo_top_right(void)
{
	t_fill	*fill;

	fill = get_fill();
	if (fill->call < fill->size_map.y)
		return (place_bot_left());
	return (place_top_left());
}

static int	algo_bot_left(void)
{
	t_fill	*fill;
	int		first_play;

	fill = get_fill();
	first_play = fill->size_map.y;
	if (fill->size_map.y < 20)
		first_play = 30;
	else if (fill->size_map.y > 95)
		first_play = fill->size_map.y / 2;
	if (fill->call < first_play)
		return (place_top_right());
	return (place_bot_right());
}

static int	algo_top_left(void)
{
	t_fill	*fill;
	int		first_play;

	fill = get_fill();
	first_play = fill->size_map.y;
	if (fill->size_map.y > 95)
		first_play = fill->size_map.y / 2;
	if (fill->call < first_play)
		return (place_bot_right());
	return (place_top_right());
}

int			algo(void)
{
	t_fill	*fill;
	int		ret;

	fill = get_fill();
	ret = 1;
	fill->call++;
	if (fill->player_pos.y < (fill->size_map.y / 2) && fill->player_pos.x <\
	(fill->size_map.x / 2))
		ret = algo_top_left();
	else if (fill->player_pos.y >= (fill->size_map.y / 2) &&\
	fill->player_pos.x < (fill->size_map.x / 2))
		ret = algo_bot_left();
	else if (fill->player_pos.y < (fill->size_map.y / 2) &&\
	fill->player_pos.x >= (fill->size_map.x / 2))
		ret = algo_top_right();
	else
		ret = algo_bot_right();
	return (ret);
}
