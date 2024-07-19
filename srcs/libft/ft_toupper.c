/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:37:35 by sshimura          #+#    #+#             */
/*   Updated: 2024/07/19 22:01:36 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

staic int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (c <= 'z' && c >= 'a')
		result = c - 32;
	return (result);
}
