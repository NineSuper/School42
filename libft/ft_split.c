/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:52:28 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/11 01:28:19 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int        ft_count_words(char const *s, char c)
{
    int    i;
    int    count;
    int    in_word;

    i = 0;
    count = 0;
    in_word = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }
        i++;
    }
    return (count);
}

static int       get_word_len(char const *s, char c)
{
    int     i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}

static char    **ft_strtab(char const *s, char c, char **tab, int count)
{
    int        i;
    int        j;
    int        len;

    i = 0;
    while (i < count)
    {
        while (*s == c)
            s++;
        len = get_word_len(s, c);
        tab[i] = (char*)malloc(sizeof(**tab) * (len + 1));
        if (!tab[i])
            return (NULL);
        j = 0;
        while (j < len)
        {
            tab[i][j] = *s;
            j++;
            s++;
        }
        tab[i][j] = '\0';
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char    **ft_split(char const *s, char c)
{
    int        word_count;
    char    **tab;

    if (!s)
        return (NULL);
    word_count = ft_count_words(s, c);
    tab = (char**)malloc(sizeof(char*) * (word_count + 1));
    if (!tab)
        return (NULL);
    tab = ft_strtab(s, c, tab, word_count);
    return (tab);
}