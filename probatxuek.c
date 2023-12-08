/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probatxuek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:43:39 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/08 15:32:43 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*int main(void)
{
    int pid;
    printf("kaixo\n");
    pid = getpid();
    printf("pid = %d\n", pid);
    return (0);
}*/

/*void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(void)
{
    int nb;

    nb = 10100111;
    ft_putchar_fd(nb, 1);
    return (0);
}*/

/*int (binary2decimal(char *binary))
{
    int nb_decimal;
	int	base;
    int i;

    nb_decimal = 0;
	base = 1;
    i = 7; //start from the rightmost bit
    while (i >= 0)
	{
		if (binary[i] == '1')
			nb_decimal = nb_decimal + base; //decimal = 0 + 1, 
		base = base*2; // 1, 2, 4, 8, 16, 32, ...
		//printf("i = %d, RTDO nb_decimal = %d, base = %d\n", i, nb_decimal, base);
		i--;
	}
	return (nb_decimal);
}

int main(void) //from binary to  char
{
    int nb_ascii;
    
    char *binary = "01100110";
    nb_ascii = binary2decimal(binary);
    printf("nb = %d\n", nb_ascii);
    return (0);
}*/

/*DESCRIPTION: 
/ --> 31 (zatikizuna) / 2 (zatitzailea) = 15 (zatidura)
% --> 31 (zatikizuna) % 2 (zatitzailea) = 1 (hondarra)
------------------------------------------------------*
int	main(void)
{
	int	nb;
	int nb_2;
	
	nb = 31 / 2;
	nb_2 = 31 % 2;
	printf("nb = %d, nb_2 = %d\n", nb, nb_2);
	return (0);
}*/

int ft_log2 (int nb)
{
	int ber;

	ber = 0;
	while (nb > 1)
	{
		nb = nb / 2;
		ber++;
	}
	return (ber);
}

/*int main(void)
{
	int result; 
	
	result = ft_log2(32);
	printf("result = %d\n", result);
	return (0);
}*/


/*int main(void)
{
	int nb;

	nb = 34;
	printf("binary of nb(%d) = %s\n", nb, dec2bin(nb));
	return (0);
}*/

int ft_2ber (int exp)
{
	int result;

	if (exp == 0)
		return (1); //edozein zenbaki ber 0 = 1
	if (exp == 1)
		return (2); //2 ber 1 = 2
	result = 2;
	while (exp > 1) //ya kasua de 2 ber 1 kontemplauta, 1 aldiz gutxiau ein bihada ber 2
	{
		result = result * 2; 
		exp--;
	}
	return (result);
}

int	assign_last(char **bin_nb, int dec)
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
	bin_nb = malloc(sizeof(char)*9);
	bin_nb[7] = assign_last(&bin_nb, dec);
	bin_nb[8] = '\0';
	exp = 0;
	i = 0;
	while (i < 7)
	{
		exp = ft_log2((int) dec);
		if (exp >= ((8 - 1) - i))
		{
			bin_nb [i] = '1';
			dec = dec - ft_2ber(exp); //actualizar valor del decimal
		}
		else
			bin_nb[i] = '0';
		i++;
	}
	return (bin_nb);
}

int main(void)
{
	int result;

	//result = ft_2ber(5);
	//printf("result = %d\n", result);
	printf("binarioa result = %s\n", dec2bin(57));
	return (0);
}
