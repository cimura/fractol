/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:09:14 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 11:36:21 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	result = lst;
	while (result != NULL && result->next != NULL)
	{
		result = result->next;
	}
	return (result);
}

// int	main(void)
// {
// 	char *data1 = "a";
// 	char *data2 = "b";
// 	char *data3 = "c";
// 	t_list *last_one;

// 	t_list *lst = ft_lstnew((void *)data1);
// 	ft_lstadd_front(&lst, ft_lstnew((void *)data2));
// 	ft_lstadd_front(&lst, ft_lstnew((void *)data3));

// 	last_one = ft_lstlast(lst);
// 	printf("last one: %s\n", lst->content);
// }