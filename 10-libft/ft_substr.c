#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	s_len = (unsigned int)ft_strlen(s);
	if (s_len == 0 || len == 0 || start >= s_len)
		return (ft_strdup(""));
	substr = malloc(MAX((s_len - start + 1), len) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != 0)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}