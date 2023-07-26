/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:16:34 by kmykhail          #+#    #+#             */
/*   Updated: 2023/04/01 14:53:15 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_put_char(char c, size_t *counter);
void	ft_put_str(char *s, size_t *counter);
void	ft_put_int_as_dec(int n, size_t *counter);
void	ft_put_uint_as_dec(unsigned int n, size_t *counter);
void	ft_put_uint_as_hex(unsigned long n, int upcase, size_t *counter);
void	ft_put_ptr(void *ptr, size_t *counter);

#endif
