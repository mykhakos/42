/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_is_prime.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 16:13:10 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/01 16:13:11 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divider;

	if (nb <= 1)
	{
		return (0);
	}
	divider = 2;
	while (divider < nb)
	{
		if (nb % divider == 0)
		{
			return (0);
		}
		divider++;
	}
	return (1);
}
