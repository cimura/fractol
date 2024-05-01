/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:40:21 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/28 20:38:23 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)&haystack[0]);
	if (haystack == NULL && n == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n && needle[j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
// 	const char *haystack;
// 	const char *needle;
// 	size_t n;

// 	haystack = "";
// 	needle = "";
// 	n = 4;
// 	char *result;

// 	result = strnstr(haystack, needle, n);
// 	printf("Original: %s\n", result);

// 	result = ft_strnstr(haystack, needle, n);
// 	printf("Mine: %s\n", result);
// }