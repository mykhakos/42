/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_recursive_power.c							   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 16:04:54 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/01 16:04:55 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
