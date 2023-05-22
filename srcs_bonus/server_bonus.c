/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:39:44 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/05/23 00:22:18 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sig_error(void)
{
	ft_putstr_fd("Signal Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	c = 0;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid && (int)(info->si_pid) != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0x01 << i);
	if (++i == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			if (kill(client_pid, SIGUSR2) == -1)
				sig_error();
		}
		else
			ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Pid: %d\n", getpid());
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	while (42)
	{
		sigaction(SIGUSR1, &sig, 0);
		sigaction(SIGUSR2, &sig, 0);
		pause();
	}
	return (0);
}
