/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:05:38 by mmahasim          #+#    #+#             */
/*   Updated: 2019/09/30 15:24:48 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(const char *s, char c)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (count);
}
