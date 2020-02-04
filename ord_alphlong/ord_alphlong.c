/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:56:26 by exam              #+#    #+#             */
/*   Updated: 2019/12/06 11:56:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_binarytree.h"
#include "ft_utils.h"
#include <unistd.h>

static void		print_words(struct s_binarytree **words, char *string, unsigned int *first, unsigned int *len)
{
	if (!words || !*words)
		return ;
	if ((*words)->left)
		print_words(&((*words)->left), string, first, len);
	if (*len < (*words)->len)
	{
		if (*len > 0)
			write(1, "\n", 1);
		*len = (*words)->len;
		*first = 0;
	}
	else if (*first)
		*first = 0;
	else
		write(1, " ", 1);
	ft_putstr(string, (*words)->word, (*words)->len);
	if ((*words)->right)
		print_words(&((*words)->right), string, first, len);
}

static void		organize_word(struct s_binarytree *word, struct s_binarytree **words, char *string)
{
	int		cmp;

	if (!words || !*words)
		*words = word;
	else
	{
		cmp = (*words)->len - word->len;
		if (cmp == 0)
			cmp = ft_strcmp(string + (*words)->word, string + word->word, (*words)->len, word->len);
		if (cmp > 0)
			organize_word(word, &((*words)->left), string);
		else
			organize_word(word, &((*words)->right), string);
	}
}

static void		get_word(struct s_binarytree *word, char *string, unsigned int *i)
{
	word->word = *i;
	while (string[*i] && !ft_isspace(string[*i]))
	{
		++(*i);
		++(word->len);
	}
}

int				main(int argc, char **argv)
{
	char					*string;
	struct s_binarytree		*words;
	struct s_binarytree		*word;
	unsigned int			i;
	unsigned int			len;
	unsigned int			nwords;

	if (argc == 2)
	{
		nwords = 0;
		i = 0;
		string = argv[1];
		while (string[i])
		{
			init_binarytree_node(&word);
			if (!word)
				return (0);
			get_word(word, string, &i);
			organize_word(word, &words, string);
			while (ft_isspace(string[i]))
				++i;
			++nwords;
		}
		if (nwords)
		{
			i = 1;
			len = 0;
			print_words(&words, string, &i, &len);
			delete_binarytree(&words);
		}
	}
	write(1, "\n", 1);
	return (0);
}
