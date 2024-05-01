/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:44:38 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/21 14:34:21 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	str_len;
	int		i;

	i = 0;
	str_len = ft_strlen((char *)str);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

//#include <string.h>
//#include <stdio.h>

//int main(void)
//{
//	char *str = "Hello!!";
//	char *ft_result;
//	char	*result;

//	printf("Before: %s\n", str);
//	printf("----------------\n");

//	ft_result = ft_strdup(str);
//	result = strdup(str);

//	if (ft_result != NULL)
//		printf("Mine: %s\n", ft_result);
//	free(ft_result);

//	if (result != NULL)
//		printf("Original: %s\n", result);
//	free(result);
//}