/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:54 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/26 11:12:46 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0' || uc > 255)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
// 	const char *s = "Hello, world.";
// 	int c;
// 	const char *result;

// 	c = 1024;

// 	result = ft_strchr(s, c);
// 	printf("Mine: %s\n", result);
// 	result = strchr(s, c);
// 	printf("Original: %s\n", result);
// }