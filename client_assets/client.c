/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:08:48 by afonso            #+#    #+#             */
/*   Updated: 2022/10/06 12:00:18 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	special_cases(char	*argv, int i)
{
	i++;
	if (argv[i] == 48)
		return (0);
	if (argv[i] == 97)
		return (7);
	if (argv[i] == 98)
		return (8);
	if (argv[i] == 116)
		return (9);
	if (argv[i] == 110)
		return (10);
	if (argv[i] == 118)
		return (11);
	if (argv[i] == 102)
		return (12);
	if (argv[i] == 114)
		return (13);
	else
		return (-1);
}

void	send_bits(unsigned int c, int server_pid)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i > 0)
	{
		bit = (unsigned char)(c & 1);
		c = *((unsigned char *) &c) >> 1;
		if (bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(350);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;
	int		chr;
	int		j;

	(void) argc;
	j = 2;
	server_pid = ft_atoi(argv[1]);
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == 92)
				chr = special_cases(argv[j], i++);
			else
				chr = argv[j][i];
			send_bits(chr, server_pid);
			i++;
		}
		j++;
	}
	return (0);
}
