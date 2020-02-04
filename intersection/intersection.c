/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:07:47 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 11:25:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	void 			*content;
	struct s_node	*next;
};

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *cur1;
	struct s_node *cur2;

	if (!lst1 || !lst2)
		return (0);
	cur1 = lst1;
	cur2 = lst2;
	while (cur1)
	{
		while (cur2)
		{
			if (cur1 == cur2)
				return (cur1);
			cur2 = cur2->next;
		}
		cur2 = lst2;
		cur1 = cur1->next;
	}
	return (0);
}

/*
**	#include <stdio.h>
**	#include <stdlib.h>
**	
**	struct s_node	*init(int value)
**	{
**		struct s_node	*node;
**		int				*content;
**	
**		node = (struct s_node *)malloc(sizeof(struct s_node));
**		if (!node)
**			return (0);
**		content = (int *)malloc(sizeof(int));
**		*content = value;
**		node->content = content;
**		node->next = 0;
**		return (node);
**	}
**	
**	int		main()
**	{
**		struct s_node	*lst1;
**		struct s_node	*lst2;
**		struct s_node	*solution;
**	
**		lst1 = init(1);
**		lst1->next = init(3);
**		lst1->next->next = init(5);
**		lst1->next->next->next = init(7);
**		lst1->next->next->next->next = init(9);
**		lst1->next->next->next->next->next = init(11);
**	
**		lst2 = 0;
**		lst2 = init(1);
**		lst2->next = init(3);
**		lst2->next->next = init(5);
**		lst2->next->next->next = init(7);
**	
**		solution = intersection(lst1, lst2);
**		if (solution)
**			printf("intersection: %d\n", *(int *)(solution->content));
**		else
**			printf("intersection: NULL\n");
**		return (0);
**	}
*/
