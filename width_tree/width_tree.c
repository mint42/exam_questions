/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:12:31 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 12:54:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct 				s_node {
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static int			get_height(struct s_node *n)
{
	int		heightl;
	int		heightr;

	if (!n)
		return (0);
	heightl = get_height(n->left) + 1;
	heightr = get_height(n->right) + 1;
	return ((heightl > heightr) ? heightl : heightr);
}

static void			recursive_width_tree(struct s_node *n, int *max_width)
{
	int		width;

	if (n->left)
		recursive_width_tree(n->left, max_width);
	width = get_height(n->left) + get_height(n->right) + 1;
	if (width > *max_width)
		*max_width = width;
	if (n->right)
		recursive_width_tree(n->right, max_width);
}

int					width_tree(struct s_node *n)
{
	int		max_width;

	if (!n)
		return (0);
	max_width = 0;
	recursive_width_tree(n, &max_width);
	return (max_width);
}
