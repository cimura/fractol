/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:49:10 by sshimura          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/06 14:53:47 by sshimura         ###   ########.fr       */
=======
/*   Updated: 2024/05/01 17:38:54 by sshimura         ###   ########.fr       */
>>>>>>> 875951fa3c1e535ad5af0460cd7f156cac3e48fc
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	count = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (count < n)
	{
		dst_ptr[count] = src_ptr[count];
		count++;
	}
	return (dst);
}
<<<<<<< HEAD
=======

#include <string.h>
#include <stdio.h>

int	main(void)
{
	unsigned char dst[2];
	unsigned char src[] = "hello";
	size_t n = 5;
	ft_memcpy(dst, src, n);
}
>>>>>>> 875951fa3c1e535ad5af0460cd7f156cac3e48fc
