/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:52:24 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/16 19:13:51 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//#include <ctype.h>

//int	main(int argc, char** argv)
//{
//	if (argc != 2)
//		return (0);
//	if (argv[1][1] != '\0')
//		printf("Judging by the first letter.\n");
//	int result = ft_isprint(argv[1][0]);
//	printf("Mine: %d\n", result);
//	result = isprint(argv[1][0]);
//	printf("Original: %d\n", result);

//}

//I don't know how to enter control characters in the shell.