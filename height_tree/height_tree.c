/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:29:35 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 00:53:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct				s_node
{
	int				value;
	struct s_node	**nodes;
};

int		height_tree(struct s_node *root)
{
	int		i;
	int		height;
	int		max_height;

	if (!root || !root->nodes)
		return (-1);
	i = 0;
	height = 0;
	max_height = 0;
	while (root->nodes[i])
	{
		height = height_tree(root->nodes[i]) + 1;
		if (height > max_height)
			max_height = height;
		++i;
	}
	return (max_height);
}

/*
**	
**	struct s_node	*make_tree()
**	{
**		struct s_node	*tree;
**	
**		tree = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->value = 94;
**	
**		tree->nodes = (struct s_node **)malloc(sizeof(struct s_node *) * 2);
**		tree->nodes[0] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[0]->value = 34;
**		tree->nodes[1] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[1]->value = 52;
**	
**		tree->nodes[0]->nodes = (struct s_node **)malloc(sizeof(struct s_node *) * 2);
**		tree->nodes[0]->nodes[0] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[0]->nodes[0]->value = 1;
**		tree->nodes[0]->nodes[1] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[0]->nodes[1]->value = 99;
**	
**		tree->nodes[0]->nodes[1]->nodes = (struct s_node **)malloc(sizeof(struct s_node *));
**		tree->nodes[0]->nodes[1]->nodes[0] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[0]->nodes[1]->nodes[0]->value = 13;
**	
**		tree->nodes[1]->nodes = (struct s_node **)malloc(sizeof(struct s_node *));
**		tree->nodes[1]->nodes[1] = (struct s_node *)malloc(sizeof(struct s_node));
**		tree->nodes[1]->nodes[1]->value = 11;
**	
**		return (tree);
**	}
**	
**	void			print_tree(struct s_node *tree)
**	{
**		int		i;
**	
**		i = 0;
**		while (tree->nodes[i])
**		{
**			print_tree(tree->nodes[i]);
**			++i;
**		}
**		printf("%d\n", tree->nodes[i]->value);
**	}
**	
**	int				main()
**	{
**		struct s_node	*tree;
**	
**		tree = make_tree();
**		printf("%d\n", height_tree(tree));
**		return (0);
**	}
**	
*/
