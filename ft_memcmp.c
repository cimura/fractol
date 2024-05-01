/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:50:38 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/19 18:05:46 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

//#include <stdio.h>

//int	main(void)
//{
//	const char	*s1 = "BCd\0dd";
//	const char	*s2 = "BCd\0ed";
//	size_t n = 6;
//	printf("s1: %s\ns2: %s\n", s1, s2);

//	printf("---------\n");

//	int	result = ft_memcmp(s1, s2, n);
//	printf("Mine: %d\n", result);

//	result = memcmp(s1, s2, n);
//	printf("Original: %d\n", result);
//}