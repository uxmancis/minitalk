/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:06:31 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/08 17:10:26 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sign2bin2char(int signal)
{
	static char	nb;
	static int	index;
	static int	i;
	char	*bin_nb;

	printf("\nHA LLEGADO LA SEÑAL!! :)");
	bin_nb = malloc(sizeof(char)*9);
	bin_nb[8] = '\0';
	i = 0;
	while (i < 8)
	{
		printf("hemen ere bai\n");
		if (signal == SIGUSR1)
			bin_nb[i] = '0';
		if (signal == SIGUSR2)
			bin_nb[i] = '1';
		if (i == 7)
		{
			binary2decimal(bin_nb);
			printf("decimal (ascii) = %d\n", nb);
			ft_putchar_fd((char)nb, 1); //imprimir char
			i = 0;
			ft_set2zero(&bin_nb, 8);
		}
		i++;
	}
	free (bin_nb);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);

	while (1)
	{
		signal(SIGUSR1, sign2bin2char);
		signal(SIGUSR2, sign2bin2char);
		pause();
	}
}
