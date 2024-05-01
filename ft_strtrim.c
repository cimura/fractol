/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:13:13 by cimy              #+#    #+#             */
/*   Updated: 2024/04/26 11:00:54 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*result;

	start = 0;
	len = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (len > start && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	result = ft_substr(s1, start, len - start);
	return (result);
}

// int main(void)
// {
// 	char const *s1 = "xxxz  test with x and z and x .  zx  xx z";
// 	char const *set = "z x";
// 	char *result;

// 	result = ft_strtrim(s1, set);
// 	printf("%s\n", result);
// }