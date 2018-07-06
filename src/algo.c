/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:36:18 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/06 09:27:48 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	case_15(void)
{
	t_fill	*fill;

	fill = get_fill();
	if (fill->player == 'O' && (fill->call % 2))
		return (place_top_right());
	else if (fill->player == 'O')
		return (place_bot_right());
	return (place_top_left());
}

static int	case_24(void)
{
	t_fill	*fill;

	fill = get_fill();
	if (fill->player == 'O' && (fill->call % 2))
		return (place_bot_right());
	else if (fill->player == 'O')
		return (place_bot_left());
	else if (fill->player == 'X' && (fill->call % 2))
		return (place_top_left());
	return (place_top_right());
}

static int	case_100(void)
{
	t_fill	*fill;

	fill = get_fill();
	if (fill->player == 'O' && (fill->call % 2))
		return (place_top_left());
	else if (fill->player == 'O')
		return (place_top_right());
	else if (fill->player == 'X' && (fill->call % 2))
		return (place_bot_left());
	return (place_bot_right());
}

int			algo(void)
{
	t_fill	*fill;
	int		ret;

	fill = get_fill();
	fill->call++;
	if (fill->size_map.y == 15)
		ret = case_15();
	else if (fill->size_map.y == 24)
		ret = case_24();
	ret = case_100();
	return (ret);
}
