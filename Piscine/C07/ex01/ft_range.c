/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_range.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/05 16:13:26 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/05 16:13:28 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*range;
	unsigned int	len;
	unsigned int	i;

	if (min >= max)
		return (0);
	len = max - min;
	range = malloc(len * sizeof(int));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

/*
#include <stdio.h>
int main()
{
	int min = -15;
	int max = 5;
	int *arr = ft_range(min, max);
	for (int i = 0; i < max - min; i++)
		printf("%i, ", arr[i]);
}
*/
