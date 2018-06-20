/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:25:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 09:39:32 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*get_piece(void)
{
	char	*line;
	char	**size;

	get_next_line(STDIN_FILENO, &line);
	size = ft_strsplit_whitespace(line);
	ft_dprintf(STDERR_FILENO, "%s", size[1]);
	return (size[1]);
}

char		*get_map(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strstr(line, "15"))
	{
		ft_strdel(&line);
		return (case_15());
	}
	else if (ft_strstr(line, "24"))
	{
		ft_strdel(&line);
		return (case_24());
	}
	ft_strdel(&line);
	return (case_100());
}

int			get_p_number(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strchr(line, '1'))
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);
}