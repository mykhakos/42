#include "libft.h"

void	*calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0 || (size && SIZE_MAX/size < num))
		return NULL;
	ptr = malloc(num * size);
	if (ptr != NULL)
		ft_bzero(ptr, num * size);
	return (ptr);
}