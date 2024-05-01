/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:36:55 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 13:22:24 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

// int	main(void)
// {
// 	char *data1 = "a";
// 	char *data2 = "b";
// 	char *data3 = "c";
// 	char *new_one = "Hi";

// 	t_list *lst = ft_lstnew((void *)data1);
// 	ft_lstadd_front(&lst, ft_lstnew((void *)data2));
// 	ft_lstadd_front(&lst, ft_lstnew((void *)data3));

// 	ft_lstadd_back(&lst, ft_lstnew((void *)new_one));
// 	t_list *last_one = ft_lstlast(lst);
// 	printf("last one: %s\n", last_one->content);
// }