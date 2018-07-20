/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:25:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/07/20 00:26:19 by rbarbazz         ###   ########.fr       */
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
	t_coord		player_pos;
	char		advers;
	char		**plateau;
	char		**piece;
	t_coord		size_piece;
	t_coord		size_map;
	t_coord		next;
	int			ret;
	int			call;
	int			match;
}				t_fill;

t_fill			*get_fill(void);

/*
** parsing
*/

int				get_player_char(void);
void			get_player_pos(void);
int				get_map(void);
char			**read_map(void);
int				get_piece(void);

/*
** algo
*/

int				algo(void);
int				test_position(t_coord next, char **map, char **piece);
int				place_top_left(void);
int				place_bot_left(void);
int				place_top_right(void);
int				place_bot_right(void);

#endif
