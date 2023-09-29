/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:52:39 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:09:10 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

int	is_number(char *str)
{
	if (*str == '\0' || str == NULL)
		return (0);
	if ((*str == '+') || (*str == '-'))
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
