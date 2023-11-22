/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:16:34 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:19:38 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "../libft_og/libft_og.h"

void	ft_put_char(char c, size_t *counter);
void	ft_put_str(char *s, size_t *counter);
void	ft_put_int_as_dec(int n, size_t *counter);
void	ft_put_uint_as_dec(unsigned int n, size_t *counter);
void	ft_put_uint_as_hex(unsigned long n, int upcase, size_t *counter);
void	ft_put_ptr(void *ptr, size_t *counter);

#endif
