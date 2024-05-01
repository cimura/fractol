/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:09:48 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/01 11:23:46 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	striteri_f(unsigned int n, char *str)
{
	str[n] += n;
}

void	ft_striteri(char *s, void (*striteri_f)(unsigned int, char *))
{
	int	j;

	j = 0;
	if (s == NULL)
		return ;
	while (s[j] != '\0')
	{
		striteri_f(j, &s[j]);
		j++;
	}
}

// int	main(void)
// {
// 	char	s[] =  "12345";
// 	printf("Before: %s\n", s);
// 	ft_striteri(s, striteri_f);
// 	printf("After: %s\n", s);
// }