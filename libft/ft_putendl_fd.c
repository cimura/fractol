/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:40:02 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/01 11:27:12 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, &*s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char	s[] = "hello";
// 	int		fd = 1;
// 	ft_putendl_fd(s, fd);
// }