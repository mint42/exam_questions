/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_binarytree.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 10:05:05 by exam              #+#    #+#             */
/*   Updated: 2019/12/06 10:52:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BINARYTREE_H
# define STRUCT_BINARYTREE_H

struct						s_binarytree
{
	unsigned int			word;
	unsigned int			len;
	struct s_binarytree		*left;
	struct s_binarytree		*right;
};

void		init_binarytree_node(struct s_binarytree **node);
void		delete_binarytree(struct s_binarytree **tree);

#endif
