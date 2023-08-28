#include "libft.h"


size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_modif;
	unsigned int	s_len;
	unsigned int	i;
	
	if (!s || !f)
		return NULL;	
	s_len = ft_strlen(s);
	s_modif = malloc((s_len + 1) * sizeof(char));
	if (!s_modif)
		return NULL;
	i = 0;
	while (i < s_len)
	{
		s_modif[i] = f(i, s[i]);
		i++;
	}
	s_modif[i] = '\0';
	return s_modif;
}
