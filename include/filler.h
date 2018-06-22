/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:25:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/06/22 18:13:16 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct	s_fill
{
	char		player;
	char		advers;
	char		**plateau;
	char		**piece;
	t_coord		size_piece;
	t_coord		size_map;
	t_coord		coord_next;
}				t_fill;

t_fill		*get_fill(void);

/*
** parsing
*/

char			get_player_char(void);
char			**get_map(void);
char			**case_15(void);
char			**case_24(void);
char			**case_100(void);
char			**get_piece(void);

/*
** algo
*/

t_coord			place_piece(void);

#endif