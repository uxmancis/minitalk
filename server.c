/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:06:31 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/27 14:36:11 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*DESCRIPTION:
sign2bin2char function receives SIGUSR1 or SIGUSR2, 1 by 1, 
8 times in total, before it prints the according char.

sign2bin2char function will be called in loop until 
total message from Client is printed in Server program's 
standard output.
--------------------------------------------------------- */
void	sign2bin2char(int signal)
{
	static char	nb;
	static int	i;
	static int	bin_nb[8];

	if (signal == SIGUSR1)
		bin_nb[i] = 0;
	else if (signal == SIGUSR2)
		bin_nb[i] = 1;
	if (i == 7)
	{
		nb = binary2decimal(bin_nb);
		ft_putchar_fd((char)nb, 1);
		i = -1;
	}
	i++;
}

/*DESCRIPTION:
Server program generates Server PID (Process Identifier) and prints it
in standard output. Then, it stays hearing, waiting for a signal 
(SIGUSR1 or SIGUSR2) to be received.

Once Server receives a signal (from Client), sign2bin2char function 
is called. 8 signals make each char from the message to be decodified.
The objective is Server program to show Client program's message
in standard output.
------------------------------------------------------------------*/
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		write (1, "Non valid format\n", 17);
		return (0);
	}
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
