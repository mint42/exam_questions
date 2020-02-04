/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:13:46 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 00:25:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_stack {
	struct s_node	*top;
};

struct s_stack			*init(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	return (stack);
}

void					*pop(struct s_stack *stack)
{
	struct s_node	*to_pop;
	void			*content;

	if (!stack || !stack->top)
		return (0);
	content = stack->top->content;
	to_pop = stack->top;
	stack->top = stack->top->next;
	free(to_pop);
	return (content);
}

void					push(struct s_stack *stack, void *content)
{
	struct s_node	*node;

	if (!stack)
		return ;
	node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!node)
		return ;
	node->content = 0;
	node->next = 0;
	if (!stack->top)
	{
		node->content = content;
		stack->top = node;
	}
	else
	{
		node->content = stack->top->content;
		node->next = stack->top->next;
		stack->top->content = content;
		stack->top->next = node;
	}
}

void					*peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->content);
}

int						isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}


/*
**	#include <stdio.h>
**	
**	int						*make_content(int n)
**	{
**		int		*content;
**	
**		content = (int *)malloc(sizeof(int));
**		if (!content)
**			return (0);
**		*content = n;
**		return (content);
**	}
**	
**	void					print_stack(struct s_stack *stack)
**	{
**		struct s_node	*cur;
**	
**		printf("stack:\n");
**		if (!stack || !stack->top)
**			return ;
**		cur = stack->top;
**		while (cur)
**		{
**			printf("%d\n", *(int *)cur->content);
**			cur = cur->next;
**		}
**	}
**	
**	int						main()
**	{
**		struct s_stack		*stack;
**		int					*content;
**		void				*popped;
**	
**		(void)content;
**		(void)popped;
**		stack = 0;
**		push(0, 0);
**		stack = 0;
**		printf("is empty: %d\n", isEmpty(stack));
**		stack = init();
**		printf("is empty: %d\n", isEmpty(stack));
**		content = make_content(54);
**		push(stack, (void *)content);
**		printf("is empty: %d\n", isEmpty(stack));
**		print_stack(stack);
**		content = make_content(55);
**		push(stack, (void *)content);
**		print_stack(stack);
**		content = make_content(56);
**		push(stack, (void *)content);
**		print_stack(stack);
**		content = make_content(57);
**		push(stack, (void *)content);
**		print_stack(stack);
**		content = make_content(58);
**		push(stack, (void *)content);
**		print_stack(stack);
**		popped = pop(stack);
**		printf("popped: %d\n", *(int *)popped);
**		print_stack(stack);
**		popped = pop(stack);
**		printf("popped: %d\n", *(int *)popped);
**		print_stack(stack);
**		popped = pop(stack);
**		printf("popped: %d\n", *(int *)popped);
**		print_stack(stack);
**		popped = pop(stack);
**		printf("popped: %d\n", *(int *)popped);
**		print_stack(stack);
**		popped = pop(stack);
**		printf("popped: %d\n", *(int *)popped);
**		print_stack(stack);
**		printf("is empty: %d\n", isEmpty(stack));
**		return (0);
**	}
*/
