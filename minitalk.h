/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:03:53 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/27 17:16:29 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> //write, getpid
# include <signal.h> //SIGUSR1, SIGUSR2, kill
# include <stdlib.h> //malloc
# include <stdio.h> //printf

//client.c file
void	ft_bin2sign2server(char *bin_nb, int s_pid);

//server.c file
void	sign2bin2char(int signal);

//utils1.c file

//utils2.c file
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		binary2decimal(int *binary);
int		ft_log2(int nb);
char	*dec2bin(char c);
int		ft_2ber(int exp);
int		assign_last(int dec);
void	ft_set2zero(int **arr, size_t len);

#endif