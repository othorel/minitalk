/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:28:35 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/21 14:28:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int	ft_atol(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return ((int)(result * sign));
}

static void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	confirm(int sign)
{
	if (sign == SIGUSR2)
		ft_printf("Message received\n");
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;
	unsigned char	*msg;

	if (ac == 3)
	{
		signal(SIGUSR2, confirm);
		pid = ft_atol(av[1]);
		msg = (unsigned char *)av[2];
		i = 0;
		while (msg[i])
		{
			send_char(pid, msg[i]);
			i++;
		}
		send_char(pid, '\0');
		pause();
	}
	else
	{
		ft_printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}
