/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:37:35 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:09 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (c <= 'z' && c >= 'a')
		result = c - 32;
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
//	int result = ft_toupper(argv[1][0]);
//	printf("Mine: %c\n", result);
//	result = toupper(argv[1][0]);
//	printf("Original: %c\n", result);
//}