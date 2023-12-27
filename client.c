/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:39:16 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/27 17:20:21 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*DESCRIPTION:
The way we'll send the chosen str from client to server is char by char.
Additionally, each of the chars will be sent using binary code (0 and 1).
*8 signals (SIGUSR1 and SIGUSR2) will be needed so that server gets
each char.

· SIGUSR1 = 0
· SIGUSR2 = 1
--------------------------------------------------------------------*/
void	ft_bin2sign2server(char *bin_nb, int s_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bin_nb[i] == '0')
			kill (s_pid, SIGUSR1);
		if (bin_nb[i] == '1')
			kill (s_pid, SIGUSR2);
		usleep(100);
		usleep(100);
		i++;
	}
	free (bin_nb);
}

/*DESCRIPTION:
Client program works as client who is sending signals to Server (server.c).

Client gets the following arguments from terminal: 
1. s_pid, Server's PID (Process IDentificator), which has previously
been printed by Server program in its standard output (terminal).
2. Message (string) that we want to send to Server.

Example of executing Client Program: (./program ServerPID "message")
./a.out 99052 "kaixo"
--------------------------------------------------------------------*/
int	main(int argc, char **argv)
{
	int		s_pid;
	int		i;
	char	*bin_nb;

	if (argc != 3)
	{
		write (1, "Non valid format\n", 17);
		return (0);
	}
	s_pid = ft_atoi(argv[1]);
	if (s_pid < 1)
	{
		write (1, "Non valid format\n", 17);
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		bin_nb = dec2bin(argv[2][i]);
		ft_bin2sign2server(bin_nb, s_pid);
		i++;
	}
	return (0);
}
