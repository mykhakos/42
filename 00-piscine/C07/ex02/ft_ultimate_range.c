/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_ultimate_range.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/05 16:13:40 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/05 16:13:42 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	len;
	unsigned int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	*range = malloc(len * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (len);
}

/*
#include <stdio.h>
int main()
{
	int *arr;
	int len;
	int min = 2;
	int max = 5;
	len = ft_ultimate_range(&arr, min, max);
	printf("len: %i\n", len);
	for (int i = 0; i < max - min; i++)
		printf("%i, ", arr[i]);
}
*/
