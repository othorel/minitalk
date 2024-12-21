/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:31:54 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/21 14:31:54 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int sign, siginfo_t *info, void *context)
{
	static int				i;
	static int				bit;
	static unsigned char	buffer[4];
	static int				index;

	(void)context;
	if (sign == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		buffer[index] = i;
		index++;
		if (index == 4 || i == 0)
		{
			ft_printf("%s", buffer);
			index = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: too many arguments\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
