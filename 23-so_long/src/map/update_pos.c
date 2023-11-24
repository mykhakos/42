/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:44:24 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 18:44:44 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map_errcode	update_pos_if_zero(int row, int col, t_map_pos *pos)
{
	if (pos->row != 0 || pos->col != 0)
		return (MULTIPLE_UNIQUE_CHARS);
	pos->row = row;
	pos->col = col;
	return (NONE);
}
