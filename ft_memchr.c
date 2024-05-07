/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:51:33 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/06 14:53:37 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;
	size_t				i;

	s_ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == (unsigned char)c)
			return ((void *)&s_ptr[i]);
		i++;
	}
	return (NULL);
}
