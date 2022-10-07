/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:02:26 by afonso            #+#    #+#             */
/*   Updated: 2022/10/06 12:02:36 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(char *number);
char	*ft_itoa(int i);
void	send_bits(unsigned int c, int server_pid);
void	send_feedback(int signal, int *bool);
int		ft_printf(const char *format, ...);
#endif
