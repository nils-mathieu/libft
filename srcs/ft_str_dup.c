/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:09:50 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 14:12:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dup(const char *s)
{
	const size_t	len = ft_str_len(s);
	char			*ret;

	ret = ft_alloc(len + 1);
	ft_mem_copy(ret, s, len + 1);
	return (ret);
}

char	*ft_str_ndup(const char *s, size_t n)
{
	const size_t	len = ft_str_nlen(s, n);
	char			*ret;

	ret = ft_alloc(len + 1);
	ft_mem_copy(ret, s, len);
	ret[len] = '\0';
	return (ret);
}
