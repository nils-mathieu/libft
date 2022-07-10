/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:26:29 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 13:57:17 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	ft_open(const char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == -1)
		ft_unwind_panic("failed to open `{s?}`");
	return (fd);
}
