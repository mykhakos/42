/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strs_to_tab.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/06 19:18:07 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/06 19:18:09 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs_data;
	int					i;

	strs_data = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!strs_data)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strs_data[i].size = ft_strlen(av[i]);
		strs_data[i].str = av[i];
		strs_data[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs_data[i].str = 0;
	return (strs_data);
}
