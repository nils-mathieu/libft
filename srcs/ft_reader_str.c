/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:35:47 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 14:38:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_reader_str(const t_reader *reader)
{
	return ((t_str){
		(const char *)(reader->data + reader->con),
		reader->cur - reader->con});
}
