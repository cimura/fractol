/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:49:10 by sshimura          #+#    #+#             */
<<<<<<< HEAD:libft/ft_memcpy.c
/*   Updated: 2024/06/19 14:15:36 by sshimura         ###   ########.fr       */
=======
/*   Updated: 2024/06/05 00:51:14 by cimy             ###   ########.fr       */
>>>>>>> a93fe424438f97c38f102c0dc508bc3f8108cfff:ft_memcpy.c
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
