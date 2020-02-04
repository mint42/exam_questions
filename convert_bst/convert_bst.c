/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:14:13 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 12:26:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void			make_circular(struct s_node **linked_list, int nnodes)
{
	struct s_node	*tmp;

	if (!*linked_list)
		return ;
	tmp = *linked_list;
	while (nnodes)
	{
		(*linked_list) = (*linked_list)->left;
		--nnodes;
	}
	(*linked_list)->left = tmp;
	tmp->right = *linked_list;
}

static void			add_node(struct s_node **linked_list, int *nnodes, struct s_node *bst)
{
	struct s_node	*tmp;

	if (!*linked_list)
	{
		*linked_list = bst;
		return ;
	}
	tmp = *linked_list;
	(*linked_list)->right = bst;
	(*linked_list) = (*linked_list)->right;
	(*linked_list)->left = tmp;
	++(*nnodes);
}

static void			build_linked_list(struct s_node **linked_list, int *nnodes, struct s_node *bst)
{
	if (bst->left)
		build_linked_list(linked_list, nnodes, bst->left);
	add_node(linked_list, nnodes, bst);
	if (bst->right)
		build_linked_list(linked_list, nnodes, bst->right);
}

struct s_node		*convert_bst(struct s_node *bst)
{
	struct s_node	*linked_list;
	int				nnodes;

	if (!bst)
		return (0);
	nnodes = 0;
	linked_list = 0;
	build_linked_list(&linked_list, &nnodes, bst);
	make_circular(&linked_list, nnodes);
	return (linked_list);
}

/*
**	#include <stdlib.h>
**	#include <stdio.h>
**	
**	static void				print_tree(struct s_node *root)
**	{
**		if (!root)
**			return ;
**		if (root->left)
**			print_tree(root->left);
**		printf("%d\n", root->value);
**		if (root->right)
**			print_tree(root->right);
**	}
**	
**	static void				print_list(struct s_node *list)
**	{
**		int				i;
**	
**		if (!list)
**			return ;
**		i = 0;
**		printf("start list:\n");
**		if (list->left)
**			printf("list->left: %d\n", list->left->value);
**		printf("list->value: %d\n", list->value);
**		if (list->right)
**			printf("list->right: %d\n", list->right->value);
**		printf("\n");
**		list = list->right;
**		while (i < 15)
**		{
**			if (list->left)
**				printf("list->left: %d\n", list->left->value);
**			printf("list->value: %d\n", list->value);
**			if (list->right)
**				printf("list->right: %d\n", list->right->value);
**			printf("\n");
**			list = list->right;
**			++i;
**		}
**	}
**	
**	static struct s_node	*init_node(int value)
**	{
**		struct s_node	*node;
**	
**		node = (struct s_node *)malloc(sizeof(struct s_node));
**		if (!node)
**			return (0);
**		node->left = 0;
**		node->right = 0;
**		node->value = value;
**		return (node);
**	}
**	
**	int							main()
**	{
**		struct s_node	*root;
**		struct s_node	*linked_list;
**	
**		root = init_node(94);
**		root->left = init_node(39);
**		root->right = init_node(99);
**		root->left->left = init_node(20);
**		root->left->left->left = init_node(1);
**		root->left->right = init_node(59);
**		root->left->right->left = init_node(44);
**		root->left->right->right = init_node(72);
**		root->left->right->left->right = init_node(50);
**		root->left->right->right->left = init_node(61);
**		root->left->right->right->right = init_node(83);
**	
**		print_tree(root);
**		printf("\n");
**		linked_list = convert_bst(root);
**		print_list(linked_list);
**		return (0);
**	}
*/
