/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:39:10 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/16 17:51:30 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	result = c;
	if (c <= 'Z' && c >= 'A')
		result = c + 32;
	return (result);
}

//#include <stdio.h>
//#include <ctype.h>

//int	main(int argc, char** argv)
//{
//	if (argc != 2)
//		return (0);
//	if (argv[1][1] != '\0')
//		printf("Judging by the first letter.\n");
//	int result = ft_tolower(argv[1][0]);
//	printf("Mine: %c\n", result);
//	result = tolower(argv[1][0]);
//	printf("Original: %c\n", result);
//}