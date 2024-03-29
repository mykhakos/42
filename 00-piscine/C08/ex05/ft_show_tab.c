/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_show_tab.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/06 19:18:35 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/06 19:18:36 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	unsigned int	nmr_tmp;

	if (nbr < 0)
	{
		ft_putchar('-');
		nmr_tmp = -nbr;
	}
	else
	{
		nmr_tmp = nbr;
	}
	if (nmr_tmp / 10 > 0)
	{
		ft_putnbr(nmr_tmp / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}
