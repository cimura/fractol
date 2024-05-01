/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:48:03 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/30 15:39:02 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(unsigned char *dst, unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[len - 1] = src[len - 1];
			len--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	ft_strncpy(dst_ptr, src_ptr, len);
	return ((void *)dst_ptr);
}

// #include <string.h>

// int	main(void)
// {
// 	char	ft_dst_ptr[100];
// 	const char	*src_ptr = "Hello";
// 	size_t	len = 4;

// 	printf("Before: %s\n", src_ptr);
// 	printf("%zu文字分コピー\n--------\n", len);

// 	char	*result;
// 	result = ft_memmove((void *)ft_dst_ptr, (const void *)src_ptr, len);
// 	printf("Mine: %s\n", result);

// 	char dst_ptr[100];
// 	result = memmove((void *)dst_ptr, (const void *)src_ptr, len);
// 	printf("Original: %s\n", result);
// }