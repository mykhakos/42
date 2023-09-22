/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:41 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:33:05 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include "../input_validation/input_validation.h"

int		*argv_to_int(int argc, char **argv);
void	exit_with_error_msg(int exit_code, char *msg);
#endif