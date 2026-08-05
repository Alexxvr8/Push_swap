/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:42:44 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/11 13:11:33 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Traverse all previously allocated strings
2 - Free each individual string
3 - Free the array of pointers itself
*/

static void	ft_free(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
		free(split[i++]);
	free(split);
}

/*
1 - Initialize a counter for the word length
2 - Count characters until the delimiter or end of string is reached
3 - Return the length of the current word
*/

static	size_t	ft_count_wlen(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

/*
1 - Initialize a counter for the number of words
2 - Skip consecutive delimiter characters
3 - Detect the start of a new word
4 - Increment the word counter
5 - Move to the end of the current word
6 - Repeat until the end of the string is reached
7 - Return the total number of words
*/

static	size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

/*
1 - Traverse the string while skipping delimiters
2 - Allocate memory for each detected word
3 - Free all previous allocations and return NULL if an allocation fails
4 - Copy the characters of the current word into the new string
5 - Add a null terminator to the copied word
6 - Store the word in the result array
7 - Repeat until all words have been processed
8 - Add a NULL pointer at the end of the array
9 - Return the completed array
*/

static	char	**ft_write_words(char	**split, char const *s, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split[word] = malloc(ft_count_wlen(s, c) + 1);
			if (!split[word])
			{
				ft_free(split, word);
				return (NULL);
			}
			i = 0;
			while (*s && *s != c)
				split[word][i++] = *s++;
			split[word][i] = '\0';
			word++;
		}
	}
	split[word] = NULL;
	return (split);
}

/*
1 - Count how many words are present in the string
2 - Allocate memory for the array of word pointers
3 - Return NULL if the allocation fails
4 - Extract and store all words into the allocated array
5 - Return the completed array of strings
*/

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc(sizeof(*split) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (ft_write_words(split, s, c));
}
