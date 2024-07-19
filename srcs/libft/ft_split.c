#include <stdio.h>
#include <stdlib.h>

// デバッグ用のprintfをマクロで定義
#define Printf()

int count_word(char const *str, char charset)
{
	int i = 0;
	int count;
	// int    flag_word_in = 0;
	if (str[0] == charset)
		count = 0;
	else
		count = 1;
	// while (str[i] == charset)
	// 	i++;
	while (str[i] != '\0')
	{
		if (str[i] == charset && str[i + 1] != charset && str[i + 1] != '\0')
			count++;
		i++;
	}
	// printf("word_count: %d\n", count);
	return (count);
}

int ft_strlen(char const *str, char charset, int indx)
{
	// char const *pointer_to_str;
	// int indx = 0;
	int count = 0;

	// pointer_to_str = str;

	// printf("in str_len \n");
	while (str[indx] == charset)
		indx++;
	while (str[indx]  != '\0')
	{
		// printf("in a loop\n");
		if (str[indx] != charset)
			count++;
		if (str[indx]  == charset)
			break;
		indx++;
	}
	// printf("str_len :%d\n", count);
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
	// printf("%d", word_count);
	result = malloc(sizeof(char *) * (word_count + 1));
	// printf("after malloc\n");
	if (!result)
		return (NULL);
	// printf("after malloc\n");

	result[word_count] = NULL;
	while (i < word_count)
	{
		j = 0;
		// printf("in a loop\n");

		str_len = ft_strlen(str, charset, str_indx);
		result[i] = malloc(str_len + 1);
		if (!*result)
			return (NULL);
		while (j < str_len)
		{
			while (str[str_indx] == charset)
				str_indx++;
			// printf("str_indx: %d\n", str_indx);
			// printf("j: %d\n", j);
			result[i][j] = str[str_indx];
			j++;
			str_indx++;
		}
		// printf("str_indx: %d\n", str_indx);
		str_indx++;
		i++;
		// printf("str_len: %d\n", str_len);
	}
	// while (!**result)
	// {

	// }

	return (result);
}
