/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:06:31 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/26 19:43:54 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*DESCRIPTION:
sign2bin2char function receives SIGUSR1 or SIGUSR2, 1 by 1, 
8 times in total, before it prints the according char.
--------------------------------------------------------- */
void	sign2bin2char(int signal)
{
	static char	nb;
	static int	index;
	static int	i;
	static int	bin_nb[8]; //ahal dot reserbau 8, eta zuzenian jartze jako '\0'.aherrero

	//printf("\nHA LLEGADO LA SEÑAL!! :)\n");
	//bin_nb = malloc(sizeof(int)*9);
	//bin_nb[8] = '\0';
	//ft_set2zero(&bin_nb, 8);
	//i = 0;
	//printf("🎄🎄🎄🎄🎄🎄🎄🎄🎄hasiran, i = %d\n", i);
	if (signal == SIGUSR1)
	{
		bin_nb[i] = 0;
		//printf("\n0 ------------ (sigusr1) | bin_nb[%d] = %d\n", i, bin_nb[i]);
	}
	else if (signal == SIGUSR2)
	{
		bin_nb[i] = 1;
		//printf("\n1 ------------ (sigusr2) | bin_nb[%d] = %d\n", i, bin_nb[i]);
	}
	if (i == 7)
	{
		//printf("8 señaleees :) LISTO IMPRIME CHAR. int *bin_nb:\n");
		//printf("bin_nb [0] = %d\n", bin_nb[0]);
		//printf("bin_nb [1] = %d\n", bin_nb[1]);
		//printf("bin_nb [2] = %d\n", bin_nb[2]);
		//printf("bin_nb [3] = %d\n", bin_nb[3]);
		//printf("bin_nb [4] = %d\n", bin_nb[4]);
		//printf("bin_nb [5] = %d\n", bin_nb[5]);
		//printf("bin_nb [6] = %d\n", bin_nb[6]);
		//printf("bin_nb [7] = %d\n", bin_nb[7]);
		nb = binary2decimal(bin_nb);
		//printf("decimal (ascii) = %d, letter: ", nb);
		ft_putchar_fd((char)nb, 1); //imprimir char
		//printf("\n\n\n");
		i = -1;
		//printf("🎁🎁🎁🎁🎁🎁🎁 RESET, i = %d\n\n\n\n\n", i);
	}
	i++;
	//printf("🎄🎄🎄🎄🎄🎄🎄🎄bukaeran, i = %d\n\n\n\n\n", i);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1); //1. Imprimir PID en servidor
	ft_putchar_fd('\n', 1);

	while (1) //2. Servidor queda en escucha
	{
		signal(SIGUSR1, sign2bin2char);
		//printf("enviada la señal 0\n");
		signal(SIGUSR2, sign2bin2char);
		//rintf("enviada la señal 1\n");
		//pause(); //program in pause until signal is received
	}
}
