/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:31:27 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 20:59:52 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*get_map_err_msg(t_map_errcode errcode)
{
	if (errcode == BORDER_NOT_CONTINUOUS)
		return ("Map border is not continuous.\n");
	if (errcode == TOO_NARROW)
		return ("Map is too narrow.\n");
	if (errcode == WIDTH_INCONSISTENT)
		return ("Map width is inconsistent.\n");
	if (errcode == CHAR_INVALID)
		return ("Map characters are invalid.\n");
	if (errcode == INVALID_CHAR_COUNT_COLLECTIBLE)
		return ("Map requires at least one collectible.\n");
	if (errcode == INVALID_CHAR_COUNT_EXIT)
		return ("Map requires one exit character.\n");
	if (errcode == INVALID_CHAR_COUNT_PLAYER)
		return ("Map requires one player position character.\n");
	if (errcode == MULTIPLE_UNIQUE_CHARS)
		return ("Map contains multiple unique characters.\n");
	if (errcode == NO_EXIT_PATH)
		return ("Map does not have an exit path.\n");
	if (errcode == NOT_ALL_COLLECTIBLES_REACHABLE)
		return ("Not all collectibles on the map are reachable.\n");
	return ("Unknown error.\n");
}

void	put_map_err_and_exit(t_map_errcode errcode)
{
	ft_printf(get_map_err_msg(errcode));
	exit(errcode);
}
