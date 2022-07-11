/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unwind_panic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:22:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/11 11:13:01 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#ifdef DEBUG

static void	end_process(int ret)
{
	(void)ret;
	abort();	
}

#else

static void	end_process(int ret)
{
	exit(ret);
}

#endif

void	ft_unwind_panic(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	ft_fmt_fd_va(STDERR_FILENO, msg, args);
	ft_write_all(STDERR_FILENO, "\n", 1);
	va_end(args);
	ft_unwind_to(0);
	end_process(1);
}
