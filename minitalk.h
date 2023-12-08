/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:03:53 by uxmancis          #+#    #+#             */
/*   Updated: 2023/12/08 16:43:32 by uxmancis         ###   ########.fr       */
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

//utils.c file
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		binary2decimal(char *binary);
int		ft_log2(int nb);
char	*dec2bin(char c);
int		ft_2ber(int exp);
char	*dec2bin(char c);
int		assign_last(char **bin_nb, int dec);
char	*ft_strcpy(char *str_src, char **str_dst);
void	ft_set2zero(char **str, size_t len);

#endif