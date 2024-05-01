/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:03 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 11:58:09 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	char *data = "hello";
// 	char *data2 = "world";
// 	t_list *lst = ft_lstnew((void *)data);
// 	ft_lstadd_front(&lst, ft_lstnew((void *)data2));

// 	int	result = 0;
// 	result = ft_lstsize(lst);
// 	printf("list size: %d\n", result);
// }