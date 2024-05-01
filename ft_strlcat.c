/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:21 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 18:03:43 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	max_copylen;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	max_copylen = size - dst_len - 1;
	if (size <= dst_len)
		return (size + src_len);
	while (i < max_copylen && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char dst[20] = "ABCDE";
// 	char *src = "1234";
// 	int size = 0;
// 	int result = ft_strlcat(NULL, src, size);
// 	printf("Return Value: %d\ndst: %s\n", result, dst);
// 	return (0);
// }