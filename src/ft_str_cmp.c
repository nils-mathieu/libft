/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:01:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/07 19:03:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_cmp(const char *a, const char *b)
{
	if (a == b)
		return (0);
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return ((int)(unsigned char)*a - (int)(unsigned char)*b);
}
