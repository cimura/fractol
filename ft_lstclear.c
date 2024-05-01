/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:40 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 16:46:33 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	char	*test1 = "hello";
// 	char	*test2 = "world";

// 	t_list	*lst = ft_lstnew(test1);
// 	ft_lstadd_front(&lst, ft_lstnew(test2));

// 	ft_lstclear(&lst, del_clear);
// }