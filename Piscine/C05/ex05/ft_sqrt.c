/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_sqrt.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 16:09:05 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/01 16:09:07 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sq_root;

	if (nb < 0 || nb > 2147395600)
	{
		return (0);
	}
	sq_root = 0;
	while (sq_root * sq_root < nb)
	{
		sq_root += 1;
	}
	if (sq_root * sq_root > nb)
	{
		return (0);
	}
	return (sq_root);
}
