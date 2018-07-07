/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/06 22:30:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill		*get_fill(void)
{
	static t_fill fill;

	return (&fill);
}

int			main(void)
{
	t_fill	*fill;

	fill = get_fill();
	fill->ret = 0;
	fill->call = 1;
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
