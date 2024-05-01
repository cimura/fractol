/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:41:39 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/24 16:16:29 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>

// int	main(int argc, char** argv)
// {
// 	if (argc != 4)
// 		return (0);
// 	else
// 	{
// 		const char *s1;
// 		const char *s2;
// 		size_t n;

// 		s1 = argv[1];
// 		s2 = argv[2];
// 		n = atoi(argv[3]);

// 		int result = ft_strncmp(s1, s2, n);
// 		printf("Mine: %d\n", result);
// 		result = strncmp(s1, s2, n);
// 		printf("Original: %d\n", result);
// 	}
// }