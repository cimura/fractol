/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:37:08 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/06 14:54:42 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_strlen_to_c(const char *s, int start, char c)
{
	int	len_count;

	len_count = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		len_count++;
		start++;
	}
	return (len_count);
}

static char	*allocate_memory(int word_len)
{
	char	*return_ptr;

	return_ptr = (char *)malloc(sizeof(char) * (word_len + 2));
	if (return_ptr == NULL)
		return (NULL);
	return (return_ptr);
}

static char	**generate_substrings(char const *s, char **before_split, char c)
{
	int	i;
	int	j;
	int	word_len;
	int	indx;

	i = 0;
	indx = 0;
	while (s[indx] != '\0')
	{
		while (s[indx] == c)
			indx++;
		if (s[indx] == '\0')
			break ;
		word_len = ft_strlen_to_c(s, indx, c);
		before_split[i] = allocate_memory(word_len);
		j = word_len - 1;
		while (j >= 0)
		{
			before_split[i][j] = s[indx + j];
			j--;
		}
		indx += word_len;
		before_split[i++][word_len] = '\0';
	}
	return (before_split);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**before_split;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	before_split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (before_split == NULL)
	{
		free(before_split);
		return (NULL);
	}
	before_split[word_count] = NULL;
	before_split = generate_substrings(s, before_split, c);
	if (before_split == NULL)
	{
		free(before_split);
		return (NULL);
	}
	return (before_split);
}
