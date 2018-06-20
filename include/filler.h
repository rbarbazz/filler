/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:25:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/20 09:40:08 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef	struct	s_fill
{
	int			p;
	char		*plateau;
	char		*piece;
}				t_fill;

/*
** parsing
*/

int				get_p_number(void);
char			*get_map(void);
char			*case_15(void);
char			*case_24(void);
char			*case_100(void);
char			*get_piece(void);

#endif