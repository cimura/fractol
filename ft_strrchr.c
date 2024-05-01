/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:39:27 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 10:27:46 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	s_len;

	s_len = ft_strlen(s);
	i = s_len;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

//#include <string.h>

//int	main(void)
//{
//	const char *s = "Hello, world.";
//	int c = '\0';
//	const char *result;

//	result = ft_strrchr(s, c);
//	printf("Mine: %s\n", result);
//	result = strrchr(s, c);
//	printf("Original: %s\n", result);
//}