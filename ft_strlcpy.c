/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:43:31 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/26 14:52:17 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

//#include <string.h>

//int main(int argc, char** argv)
//{
//	if (argc != 3)
//		return (0);
//	printf("MINE:\n");
//	char dst[10];
//	const char	*src = argv[1];
//	size_t size = atoi(argv[2]);

//	size_t ft_result = ft_strlcpy(dst, src, size);
//	printf("The number of characters is %zu\n", ft_result);
//	printf("ft_dst: %s\n\n", dst);

//	printf("ORIGINAL:\n");
//	char ft_dst[10];
//	size_t result = strlcpy(ft_dst, src, size);
//	printf("The number of characters is %zu\n", result);
//	printf("dst: %s\n", dst);
//}