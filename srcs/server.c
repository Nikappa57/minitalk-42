/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:39:44 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/05/22 23:26:50 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig)
{
	static int	i = 0;
	static int	c = 0;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	c <<= 1;
	usleep(100);
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	while (42)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
