#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*arr;
	int	i;

	arr = malloc((length + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (*tab)
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}