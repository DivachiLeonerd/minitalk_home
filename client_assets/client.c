/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:08:48 by afonso            #+#    #+#             */
/*   Updated: 2022/06/21 11:06:57 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	char	*server_pid;
	char	*string;

	server_pid = argv[1];
	string = argv[2];
	kill(ft_atoi(server_pid), SIGUSR1);
}
