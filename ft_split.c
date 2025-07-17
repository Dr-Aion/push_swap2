/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:40:05 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/17 17:25:55 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	bool	inside_word;
	int		count;

	inside_word = false;
	count = 0;
	while (*str)
	{
		if (*str != separator && !inside_word)
		{
			count++;
			inside_word = true;
		}
		else if (*str == separator)
			inside_word = false;
		str++;
	}
	return (count);
}

char	*get_next_word(char *str, char separator, int *cursor)
{
	int			len;
	char		*next_str;
	int			i;

	len = 0;
	i = 0;
	if (!str || !cursor)
		return (NULL);
	while (str[*cursor] == separator && str[*cursor])
		(*cursor)++;
	while (str[(*cursor) + len] != separator && str[(*cursor) + len])
		len++;
	next_str = malloc(sizeof(char) * (len + 1));
	if (next_str == NULL)
		return (NULL);
	while (str[*cursor] != separator && str[*cursor])
	{
		next_str[i] = str[*cursor];
		(*cursor)++;
		i++;
	}
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		num_of_words;
	char	**arr_of_str;
	int		i;
	int		cursor;

	i = 0;
	cursor = 0;
	num_of_words = count_words(str, separator);
	arr_of_str = malloc(sizeof(char *) * (num_of_words + 1));
	if (arr_of_str == NULL)
		return (NULL);
	while (i < num_of_words)
	{
		arr_of_str[i] = get_next_word(str, separator, &cursor);
		if (arr_of_str[i] == NULL)
		{
			while (i--)
				free(arr_of_str[i]);
			free(arr_of_str);
			return (NULL);
		}
		i++;
	}
	arr_of_str[i] = NULL;
	return (arr_of_str);
}
