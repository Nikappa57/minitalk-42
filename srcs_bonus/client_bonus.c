/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:40:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/05/22 23:37:45 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sig_error(void)
{
	ft_putstr_fd("Signal Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	send_str(int pid, char *str)
{
	int		shift;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if (str[i] & (1 << shift--))
			{
				if (kill(pid, SIGUSR2) == -1)
					sig_error();
			}
			else if (kill(pid, SIGUSR1) == -1)
				sig_error();
			usleep(100);
		}
		i++;
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Message receved.\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isstrdigit(argv[1]))
	{
		ft_putstr_fd("Args error, use:\n./client <PID> <STR>\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, sig_handler);
	send_str(ft_atoi(argv[1]), argv[2]);
	while (42)
		pause();
}
