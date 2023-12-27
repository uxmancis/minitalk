/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:54:26 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/27 17:22:59 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	binary2decimal(int *binary)
{
	int	nb_decimal;
	int	base;
	int	i;

	nb_decimal = 0;
	base = 1;
	i = 7;
	while (i >= 0)
	{
		if (binary[i] == 1)
			nb_decimal = nb_decimal + base;
		base = base * 2;
		i--;
	}
	return (nb_decimal);
}

int	ft_log2(int nb)
{
	int	ber;

	ber = 0;
	while (nb > 1)
	{
		nb = nb / 2;
		ber++;
	}
	return (ber);
}

int	ft_2ber(int exp)
{
	int	result;

	if (exp == 0)
		return (1);
	if (exp == 1)
		return (2);
	result = 2;
	while (exp > 1)
	{
		result = result * 2;
		exp--;
	}
	return (result);
}

int	assign_last(int dec)
{
	int	i;

	if (dec % 2 == 1)
		i = '1';
	else
		i = '0';
	return (i);
}

/*DESCRIPTION: 
dec2bin
1. char --> nb bihurtu (atoi)
2. nb (ascii) --> binario
----------------------------------------*/
char	*dec2bin(char c)
{
	int		exp;
	char	*bin_nb;
	int		i;
	int		dec;

	dec = (int) c;
	bin_nb = malloc(sizeof(char) * 9);
	bin_nb[7] = assign_last(dec);
	bin_nb[8] = '\0';
	exp = 0;
	i = 0;
	while (i < 7)
	{
		exp = ft_log2((int) dec);
		if (exp >= ((8 - 1) - i))
		{
			bin_nb[i] = '1';
			dec = dec - ft_2ber(exp);
		}
		else
			bin_nb[i] = '0';
		i++;
	}
	return (bin_nb);
}
