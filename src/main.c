/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/25 20:16:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill		*get_fill(void)
{
	static t_fill fill;

	return (&fill);
}

int			main(int argc, char **argv)
{
	t_fill	*fill;

	if (argc != 1 || !argv[0])
		return (-1);
	fill = get_fill();
	fill->player = get_player_char();
	while (1)
	{
		fill->plateau = get_map();
		fill->piece = get_piece();
		place_piece();
		strstr_free(fill->plateau);
		strstr_free(fill->piece);
		ft_printf("%d %d\n", fill->coord_next.y, fill->coord_next.x);
	}
	return (0);
}