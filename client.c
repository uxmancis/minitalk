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
	printf("received bin_nb = %s\n", bin_nb);
	while (i < 8)
	{
		if (bin_nb[i] == '0')
		{
			//printf("enviar 0\n");
			kill (s_pid, SIGUSR1);
		}
		if (bin_nb[i] == '1')
		{
			//printf("enviar 1\n");
			kill (s_pid, SIGUSR2);
		}
		usleep(100);
		i++;
	}
}

/*DESCRIPTION:
client.c works as client who is sending signals to server (server.c).

client gets s_pid, Server's PID (Process IDentificator), as an argument from
terminal (Server has previously printed its PID in standard output (terminal).
--------------------------------------------------------------------*/
int	main(int argc, char **argv)
{
	int s_pid;
	int i;
	char *bin_nb;

	if (argc != 3)
		write (1, "Non valid format\n", 16);
	s_pid = ft_atoi(argv[1]);
	bin_nb = malloc(sizeof(char)*9);
	bin_nb[8] = '\0';
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_strcpy(dec2bin(argv[2][i]), &bin_nb); //get binary of the char.
		//printf("bin = %s\n", bin_nb);
		ft_bin2sign2server(bin_nb, s_pid); //send binary
		i++;
	}
	//ft_strcpy(dec2bin(argv[2][0]), bin);
	//printf("result copiado en bin = %s\n", bin);
	free (bin_nb);
	return (0);
}
