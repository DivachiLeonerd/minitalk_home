/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:02:08 by afonso            #+#    #+#             */
/*   Updated: 2022/06/21 18:10:03 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	print_hello(int signal)
{
	printf("signal:%d\n", signal);
	write(1, "HELLO WORLD\n", 13);
	return ;
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sigact;
	struct sigaction	old_sigact;
	sigset_t			sigset;

	while (1)
	{
		sigact.sa_flags = SA_RESTART;
		sigact.sa_handler = &print_hello;
		pid = getpid();
		printf("PID:%d\n", pid);
		sigaction(SIGUSR1, &sigact, NULL);
		pause();
	}
}
