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

#include "../includes/minitalk_bonus.h"

static void	reset_message(char *msg, int *index)
{
	msg[*index] = '\0';
	ft_printf("Received message : %s\n", msg);
	*index = 0;
}

static void	append_to_buffer(char byte, char *msg, int *index)
{
	msg[*index] = byte;
	(*index)++;
	if (*index >= 1024)
	{
		ft_printf("Error : message too long.\n");
		*index = 0;
	}
}

void	handler(int sign, siginfo_t *info, void *context)
{
	static int		bit;
	static char		byte;
	static char		msg[1024];
	static int		index;

	(void)context;
	if (sign == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\0')
		{
			reset_message(msg, &index);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			append_to_buffer(byte, msg, &index);
		}
		bit = 0;
		byte = 0;
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
	ft_printf("Server PID : %d\n", pid);
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
