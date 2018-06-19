/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/19 17:31:21 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_p_number(void)
{
	char	*line;

	get_stdin(STDIN_FILENO, &line);
	ft_dprintf(STDERR_FILENO, "%s", line);
	return (1);
}

t_fill		*get_fill(void)
{
	static t_fill fill;

	return (&fill);
}

int			main(void)
{
	t_fill	*fill;

	fill = get_fill();
	fill->p = get_p_number();
	char	*line;

	get_stdin(STDIN_FILENO, &line);
	ft_dprintf(STDERR_FILENO, "%s", line);
	while (1)
	{

	}
	return (0);
}