/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:51:33 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 10:26:59 by sshimura         ###   ########.fr       */
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

// #include <string.h>

// int	main(void)
// {
// 	const char	*s = "Hello";
// 	int	c = 'l';
// 	size_t	n = 3;
// 	printf("Before: %s\n-----\n", s);

// 	char	*result;
// 	result = ft_memchr((const void *)s, c, n);
// 	printf("Mine: %s\n", result);

// 	result = memchr((const void *)s, c, n);
// 	printf("Original: %s\n", result);
// }