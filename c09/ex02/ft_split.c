/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:34:17 by elahrach          #+#    #+#             */
/*   Updated: 2023/10/05 12:35:05 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*str != '\0')
	{
		if (is_separator(*str, charset))
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*get_next_word(char **str, char *charset)
{
	char	*word_start;
	int		word_len;
	char	*word;
	int		i;

	while (**str != '\0' && is_separator(**str, charset))
		(*str)++;
	word_start = *str;
	while (**str != '\0' && !is_separator(**str, charset))
		(*str)++;
	word_len = *str - word_start;
	word = (char *)malloc(word_len + 1);
	if (!word)
		return (NULL);
	if (word)
	{
		i = 0;
		i--;
		while (i++ < word_len)
			word[i] = word_start[i];
		word[word_len] = '\0';
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*temp_str;
	int		num_words;
	int		index;

	num_words = count_words(str, charset);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	temp_str = str;
	while (*temp_str != '\0')
	{
		if (!is_separator(*temp_str, charset))
			result[index++] = get_next_word(&temp_str, charset);
		else
			temp_str++;
	}
	result[index] = NULL;
	return (result);
}

#include <stdio.h>
int main() {
    char *str = "Hello$World!This,Is,My,Test";
    char *charset = ",!$";
    
    char **result = ft_split(str, charset);
    
    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);
        }
        
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    
    return 0;
}

