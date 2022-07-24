/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_aget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:15:41 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/24 19:19:49 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t ft_reader_aget(t_reader *reader, size_t index)
{
	uint8_t	byte;

	if (!ft_reader_get(reader, index, &byte))
		ft_unwind_panic("unexpected end of file");
	return (byte);
}
