/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unwind_panic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:22:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 18:24:41 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_unwind_panic(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	ft_fmt_fd_va(STDERR_FILENO, msg, args);
	va_end(args);
	ft_unwind_to(0);
	exit(1);
}
