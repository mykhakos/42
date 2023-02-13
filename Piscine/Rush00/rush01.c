/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:23:58 by apylypen          #+#    #+#             */
/*   Updated: 2022/11/20 16:24:01 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	check_if_positive(int x, int y)
{
	int		is_positive;
	char	*err_msg;
	int		i;

	is_positive = 1;
	i = 0;
	err_msg = "Input should be a positive integer.\n";
	if (x <= 0 || y <= 0)
	{
		is_positive = 0;
		if (x < 0 || y < 0)
		{
			while (err_msg[i] != '\0')
			{
				ft_putchar(err_msg[i]);
				i++;
			}
		}
	}
	return (is_positive);
}

void	ft_print_row(char start_c, char mid_c, char end_c, int width)
{
	int	wi;

	wi = 1;
	ft_putchar(start_c);
	while (wi < width - 1)
	{
		ft_putchar(mid_c);
		wi++;
	}
	if (width > 1)
	{
		ft_putchar(end_c);
	}
	ft_putchar('\n');
}

int	_rush(int x, int y, char rush_chars[])
{
	int		yi;

	yi = y;
	if (check_if_positive(x, y) == 0)
	{
		return (1);
	}
	while (yi > 0)
	{
		if (yi == y)
		{
			ft_print_row(rush_chars[0], rush_chars[4], rush_chars[1], x);
		}
		else if (yi == 1)
		{
			ft_print_row(rush_chars[2], rush_chars[4], rush_chars[3], x);
		}
		else
		{
			ft_print_row(rush_chars[5], ' ', rush_chars[5], x);
		}
		yi--;
	}
	return (0);
}

void	rush(int x, int y)
{
	_rush(x, y, "/\\\\/**");
}
