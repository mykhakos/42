/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:14:13 by kmykhail          #+#    #+#             */
/*   Updated: 2022/12/05 16:14:15 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_numlen(int nbr, int basesize)
{
	int	len;

	len = 0;
	while (nbr / basesize != 0)
	{
		len++;
		nbr /= basesize;
	}
	if (nbr < 0)
		len += 1;
	return (len + 1);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char			*strnbr;
	unsigned int	nbr_tmp;
	int				len;
	int				basesize;

	basesize = ft_check_base(base);
	if (basesize < 2)
		return (NULL);
	len = ft_numlen(nbr, basesize);
	strnbr = malloc((len + 1) * sizeof(char));
	strnbr[len] = '\0';
	if (nbr < 0)
	{
		strnbr[0] = '-';
		nbr_tmp = -nbr;
	}
	else
		nbr_tmp = nbr;
	while (nbr_tmp / basesize != 0)
	{
		strnbr[--len] = base[nbr_tmp % basesize];
		nbr_tmp /= basesize;
	}
	strnbr[len - 1] = base[nbr_tmp % basesize];
	return (strnbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num_dec;
	char	*num;
	int		basesize_from;
	int		basesize_to;

	basesize_from = ft_check_base(base_from);
	basesize_to = ft_check_base(base_to);
	if (basesize_from < 2 || basesize_to < 2)
		return (NULL);
	num_dec = ft_atoi_base(nbr, base_from);
	num = ft_itoa_base(num_dec, base_to);
	return (num);
}

/*
int main()
{
	char *num_from = "--323";
	char *base_from = "9876543210";
	char *num_to;
	char *base_to = "456789";
	num_to = ft_convert_base(num_from, base_from, base_to);
	printf("%s\n", num_to);
	return 0;
}
*/