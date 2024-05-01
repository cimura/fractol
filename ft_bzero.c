/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:56:10 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/21 13:09:51 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}

//int	main(void)
//{
//	size_t ft_str[] = {1, 2, 3, 4};
//	size_t len = 2;	

//	printf("Before: ");
//	for(size_t i = 0; i < sizeof(ft_str) / sizeof(size_t); i++)
//		printf("%zu ", ft_str[i]);
//	printf("\n");

//	ft_bzero(ft_str, len * sizeof(size_t));
//	printf("Mine: ");
//	for(size_t j = 0; j < sizeof(ft_str) / sizeof(size_t); j++)
//		printf("%zu ", ft_str[j]);
//	printf("\n");

//	size_t str[] = {1, 2, 3, 4};
//	bzero(str, len * sizeof(size_t));
//	printf("Original: ");
//	for(size_t k = 0; k < sizeof(str) / sizeof(size_t); k++)
//		printf("%zu ", str[k]);
//	printf("\n");
//	return (0);
//}