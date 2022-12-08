/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_find_next_prime.c							   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 16:22:53 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/01 16:22:55 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned long long	divider;
	unsigned long long	nb_tmp;

	nb_tmp = nb;
	if (nb <= 1)
		return (0);
	divider = 2;
	while (divider * divider < nb_tmp)
	{
		if (nb % divider == 0)
			return (0);
		divider++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
