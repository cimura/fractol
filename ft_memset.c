/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:47:17 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/21 13:11:20 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_ptr;
	size_t			i;

	b_ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_ptr[i] = c;
		i++;
	}
	return ((void *)b_ptr);
}

//#include <string.h>

//int	main(void)
//{
//	char str[] = "Hello";
//	size_t len = 2;
//	int	c = 'k';

//	printf("Before: %s\n", str);

//	ft_memset(str+1, c, len);
//	printf("Mine: %s\n", str);

//	memset(str+1, c, len);
//	printf("Original: %s\n", str);
//	return (0);
//}