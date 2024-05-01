/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura < sshimura@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:52:56 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/21 13:10:32 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
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
//	int result = ft_isdigit(argv[1][0]);
//	printf("Mine: %d\n", result);
//	result = isdigit(argv[1][0]);
//	printf("Original: %d\n", result);
//}