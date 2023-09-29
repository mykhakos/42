/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:52:10 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:16:00 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H

# include "limits.h"
# include "../../libft/libft.h"

int	is_number(char *str);
int	is_int(char *nbr);
int	has_dup(int *arr, int arr_len);

#endif