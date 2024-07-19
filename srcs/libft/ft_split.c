/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:12:46 by cimy              #+#    #+#             */
/*   Updated: 2024/07/20 01:14:47 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_word(char const *str, char charset)
{
	int i = 0;
	int count;
	if (str[0] == charset)
		count = 0;
	else
		count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == charset && str[i + 1] != charset && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int len_str(char const *str, char charset, int indx)
{
	int count = 0;

	while (str[indx] == charset)
		indx++;
	while (str[indx]  != '\0')
	{
		if (str[indx] != charset)
			count++;
		if (str[indx]  == charset)
			break;
		indx++;
	}
	return (count);
}

char **ft_split(char const *str, char charset)
{
	char **result;
	int word_count = 0;
	int i = 0;
	int j;
	int str_len = 0;
	int str_indx = 0;

	word_count = count_word(str, charset);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	result[word_count] = NULL;
	while (i < word_count)
	{
		j = 0;
		str_len = len_str(str, charset, str_indx);
		result[i] = malloc(str_len + 1);
		if (!*result)
			return (NULL);
		while (j < str_len)
		{
			while (str[str_indx] == charset)
				str_indx++;
			result[i][j] = str[str_indx];
			j++;
			str_indx++;
		}
		str_indx++;
		i++;
	}
	return (result);
}
