/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:02:08 by afonso            #+#    #+#             */
/*   Updated: 2022/10/06 11:34:54 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	ft_power(unsigned char base, unsigned char power)
{
	unsigned char	sum;

	sum = 1;
	while (power)
	{
		sum = sum * base;
		power--;
	}
	return (sum);
}

void	read_signals(int signal)
{
	static unsigned int		c;
	static int				counter;

	if (signal == SIGUSR1)
		c += ft_power(2, counter);
	counter++;
	if (counter == 8)
	{
		counter = 0;
		write(1, &c, 1);
		c = 0;
	}
	return ;
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sigact;

	sigact.sa_flags = SA_RESTART;
	sigact.sa_handler = read_signals;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	pid = getpid();
	ft_printf("PID:%d\n", pid);
	while (1)
		pause();
}
