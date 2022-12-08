/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:40:40 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/21 18:39:19 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_write(char d1, char n1, char d2, char n2)
{
	write(1, &d1, 1);
	write(1, &n1, 1);
	write(1, " ", 1);
	write(1, &d2, 1);
	write(1, &n2, 1);
	if (d1 != '9' || n1 != '8' || d2 != '9' || n2 != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_count(char add_num, char *num_pt, char *doz_pt)
{
	if (add_num == -1)
	{
		add_num = *num_pt;
	}
	*num_pt = add_num + 1;
	if (*num_pt > '9')
	{
		*doz_pt += 1;
		*num_pt = '0';
	}
}

void	ft_print_comb2(void)
{
	char	doz1;
	char	num1;
	char	doz2;
	char	num2;

	doz1 = '0';
	num1 = '0';
	doz2 = '0';
	num2 = '1';
	while (doz1 + doz2 <= 57 + 57)
	{
		ft_write(doz1, num1, doz2, num2);
		ft_count(-1, &num2, &doz2);
		if (doz2 > '9')
		{
			ft_count(-1, &num1, &doz1);
			doz2 = doz1;
			ft_count(num1, &num2, &doz2);
		}
	}
}
