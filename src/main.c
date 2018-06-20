/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 09:40:11 by rbarbazz         ###   ########.fr       */
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

//check if program is used as argument
	if (argc != 1)
		return (-1);
	if (argv[0])
	{}
	fill = get_fill();
	fill->p = get_p_number();
	ft_dprintf(STDERR_FILENO, "player %d\n", fill->p);
	fill->plateau = get_map();
	ft_dprintf(STDERR_FILENO, "plateau :\n%s", fill->plateau);
	get_piece();
	return (0);
}