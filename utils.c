/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:47:28 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/08 16:34:51 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n *(-1);
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd ((n % 10) + 48, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				sign = -1;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + (str[i] - 48);
			i++;
		}
		return (num * sign);
	}
	return (0);
}

void	ft_set2zero(char **str, size_t len)
{
	int	i;

	i = 0;
	(*str)[len] = '\0';
	while (len > 1)
	{
		(*str)[i] = '0';
		i++;
		len--;
	}
}

/*int	ft_nodivisions(int n)
{
	int	i;

	i = 0;
	while (1)
	{
		n = n / 10;
		i++;
		if (n == 0)
			break ;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*str_result;
	int		size;
	long	number;

	number = nb;
	size = ft_nodivisions(number) + 1;
	if (number < 0)
		size++;
	str_result = malloc(sizeof(char) * size);
	if (!str_result)
		return (0);
	if (number < 0)
	{
		str_result[0] = '-';
		number *= -1;
	}
	str_result[--size] = '\0';
	while (1)
	{
		str_result[size-- - 1] = (number % 10) + '0';
		number /= 10;
		if (number == 0)
			break ;
	}
	return (str_result);
}*/

int binary2decimal(char *binary)
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

char	*ft_strcpy(char *str_src, char **str_dst)
{
	int	i;

	i = 0;
	while (str_src[i] != '\0')
	{
		(*str_dst)[i] = str_src[i];
		i++;
	}
	return (*str_dst);
}
