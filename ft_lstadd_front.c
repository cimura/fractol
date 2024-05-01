/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:43:20 by sshimura          #+#    #+#             */
/*   Updated: 2024/04/29 11:04:19 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	char	*str = "hello";
// 	t_list	*lst = NULL;
// 	t_list	*new;

// 	new = ft_lstnew((void *)str);

// 	ft_lstadd_front(&lst, new);
// 	t_list	*current = lst;

// 	while (current != NULL)
// 	{
// 		printf("current->content: %s\n", (char *)current->content);
// 		current = current->next;
// 	}
// }