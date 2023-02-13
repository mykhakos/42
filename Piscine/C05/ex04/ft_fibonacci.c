/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_fibonacci.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 16:06:43 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/01 16:06:45 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
