/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:35:39 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/24 11:27:19 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

//int	main(int argc, char* argv[])
//{
//	if (argc != 2)
//		return (0);
//	else
//	{
//		int result = ft_strlen(argv[1]);
//		printf("%d\n", result);
//	}
//}