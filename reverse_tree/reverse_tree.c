/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:41:45 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:00:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	reverse_tree(struct s_node *root)
{
	struct s_node *tmp;

	if (!root)
		return ;
	if (root->left)
		reverse_tree(root->left);
	if (root->right)
		reverse_tree(root->right);
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}


/*
**	#include <stdio.h>
**	#include <stdlib.h>
**	
**	struct s_node	*init(int value)
**	{
**		struct s_node	*node;
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
**	void			print_tree(struct s_node *tree)
**	{
**		if (!tree)
**			return ;
**		if (tree->left)
**			print_tree(tree->left);
**		printf("%d\n", tree->value);
**		if (tree->right)
**			print_tree(tree->right);
**	}
**	
**	int				main()
**	{
**		struct s_node	*tree;
**	
**		tree = init(94);
**		tree->left = init(34);
**		tree->right = init(52);
**		tree->left->left = init(1);
**		tree->left->left->left = init(20);
**		tree->left->right = init(99);
**		tree->left->right->left = init(83);
**		tree->left->right->right = init(39);
**		tree->left->right->left->right = init(61);
**		tree->left->right->right->left = init(37);
**		tree->left->right->right->right = init(67);
**	
**		print_tree(tree);
**		printf("\n");
**		reverse_tree(tree);
**		print_tree(tree);
**		return (0);
**	}
*/
