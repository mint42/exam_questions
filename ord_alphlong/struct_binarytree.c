/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 10:04:42 by exam              #+#    #+#             */
/*   Updated: 2019/12/06 11:41:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_binarytree.h"
#include <stdlib.h>

void		init_binarytree_node(struct s_binarytree **node)
{
	*node = (struct s_binarytree *)malloc(sizeof(struct s_binarytree));
	if (!*node)
		return ;
	(*node)->word = 0;
	(*node)->len = 0;
	(*node)->left = 0;
	(*node)->right = 0;
}

void		delete_binarytree(struct s_binarytree **tree)
{
	if (!tree)
		return ;
	if ((*tree)->left)
		delete_binarytree(&((*tree)->left));
	if ((*tree)->right)
		delete_binarytree(&((*tree)->right));
	free((void *)*tree);
}
