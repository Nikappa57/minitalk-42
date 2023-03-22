/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:32:58 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/22 15:19:44 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putpid(void)
{
	ft_putstr_fd("Pid: ", 0);
	ft_putnbr_fd(getpid(), 0);
	ft_putchar_fd('\n', 0);
}

int	main(void)
{
	ft_putpid();
	return (0);
}
