/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:24:07 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/22 20:24:12 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alnum(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
	{
		return (0);
	}
	else
	{
		return (1);
	}		
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (i == 0 || is_alnum(str[i - 1]) == 0))
		{
			str[i] = str[i] - 'a' + 'A';
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z')
			&& (is_alnum(str[i - 1]) == 1))
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}
