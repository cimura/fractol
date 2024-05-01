/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:55:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 16:49:28 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIZE 1000000

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count < 0 || size < 0)
		return (NULL);
	if (count > SIZE || size > SIZE)
		return (NULL);
	if (SIZE_MAX / count < size)
		return (NULL);
	total_size = count * size;
	ptr = (unsigned char *)malloc(sizeof(unsigned char) * total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// size has already been decided.

// int main(void)
// {
// 	char *ft_mem;
// 	char *mem;
// 	size_t i = 0;
// 	size_t count = 0;

// 	ft_mem = ft_calloc(0, 0);

// 	if (ft_mem != NULL)
// 	{
// 		printf("--- Mine ---\n");
// 		printf("Allocated memory: ");
// 		while (i < count)
// 		{
// 			printf("%d ", ft_mem[i]);
// 			i++;
// 		}
// 		free(ft_mem);
// 	}
// 	printf("\n\n");

// 	mem = calloc(0, 0);
// 	i = 0;

// 	if (mem != NULL)
// 	{
// 		printf("--- Original ---\n");
// 		printf("Allocated memory: ");
// 		while (i < count)
// 		{
// 			printf("%d ", mem[i]);
// 			i++;
// 		}
// 		free(mem);
// 	}
// 	printf("\n");
// 	return (0);
// }