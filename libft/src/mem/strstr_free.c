/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:04:09 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/20 18:56:06 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strstr_free(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
		ft_strdel(&str[i++]);
	if (str)
		ft_memdel((void**)&str);
}
