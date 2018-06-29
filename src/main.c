/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/29 16:10:14 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill		*get_fill(void)
{
	static t_fill fill;

	return (&fill);
}

static int	algo(void)
{
	t_fill	*fill;
	int		ret;

	fill = get_fill();
	fill->call++;
	if (fill->size_map.y == 15 && fill->player == 'O' && (fill->call % 2))
		ret = place_bot_right();
	else if (fill->size_map.y == 15 && fill->player == 'O')
		ret = place_top_right();
	else if (fill->player == 'O')
		ret = place_bot_left();
	else
		ret = place_top_left();
	return (ret);
}

int			main(void)
{
	t_fill	*fill;

	fill = get_fill();
	fill->ret = 0;
	fill->call = 0;
	if (get_player_char() == 1)
		return (-1);
	while (1)
	{
		if (get_map() || get_piece() || algo())
			break ;
		strstr_free(fill->plateau);
		strstr_free(fill->piece);
		ft_printf("%d %d\n", fill->next.y, fill->next.x);
	}
	ft_printf("0 0\n");
	strstr_free(fill->plateau);
	strstr_free(fill->piece);
	return (0);
}
