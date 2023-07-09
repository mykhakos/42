/* ************************************************************************** */
/*																		    	*/
/*														:::	  ::::::::   */
/*   ft_strdup.c										    :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	    */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+	    	*/
/*												+#+#+#+#+#+   +#+		     */
/*   Created: 2022/12/05 16:13:13 by kmykhail		  #+#	#+#			     */
/*   Updated: 2023/02/17 16:13:19 by kmykhail		 ###   ########.fr	     */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*dest;

	if (src == NULL)
		return NULL;
	src_len = ft_strlen(src);
	dest = malloc((src_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i <= src_len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

