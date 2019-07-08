/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:33:30 by tin               #+#    #+#             */
/*   Updated: 2019/07/08 16:33:32 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//FAUT IL GERER LES POWER DE NBES NEG ??
int	ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return (nb);
	if(power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
