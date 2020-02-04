/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:09:29 by exam              #+#    #+#             */
/*   Updated: 2019/08/20 10:46:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static void		get_longest_sequence(struct s_node *node, int *length, int *longest, int n)
{
	if (!node)
		return ;
	if (n == node->value - 1)
		++*length;
	else
		*length = 1;
	if (*length > *longest)
		*longest = *length;
	if (node->left)
		get_longest_sequence(node->left, length, longest, node->value);
	if (node->right)
		get_longest_sequence(node->right, length, longest, node->value);
}

int				longest_sequence(struct s_node *node)
{
	int		length;
	int		longest;

	if (!node)
		return (0);
	length = 1;
	longest = 1;
	get_longest_sequence(node, &length, &longest,  node->value);
	return (longest);
}

/*
**	#include <stdio.h>
**	#include <stdlib.h>
**	
**	static struct s_node	*init(int value)
**	{
**		struct s_node *node;
**	
**		node = (struct s_node *)malloc(sizeof(struct s_node));
**		if (!node)
**			return (0);
**		node->value = value;
**		node->left = 0;
**		node->right = 0;
**		return (node);
**	}
**	
**	static void		printtree(struct s_node *node)
**	{
**		if (!node)
**			return ;
**		if (node->left)
**			printtree(node->left);
**		printf("%d\n", node->value);
**		if (node->right)
**			printtree(node->right);
**	}
**	
**	int				main()
**	{
**		struct s_node	*node;
**	
**		node = init(30);
**		node->left = init(15);
**		node->right = init(41);
**		node->left->left = init(61);
**		node->right->left = init(80);
**		node->right->left->right = init(81);
**	
**		printtree(node);
**		printf("longest: %d\n", longest_sequence(node));
**		return (0);
**	}
*/
