/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:55:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/06 14:52:16 by sshimura         ###   ########.fr       */
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
