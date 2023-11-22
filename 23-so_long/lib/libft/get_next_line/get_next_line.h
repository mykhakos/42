/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:43:05 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:17:31 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft_og/libft_og.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
int		ft_find_nl(const char *s);

#endif
