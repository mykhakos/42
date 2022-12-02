#include <stdio.h>
#include <stdlib.h>

int is_delim(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int ft_word_count(char *str)
{
    int word_count;

    word_count = 0;
    while (*str)
    {
        while (*str && is_delim(*str))
            str++;
        if (*str && !is_delim(*str))
            word_count += 1;
        while (*str && !is_delim(*str))            
            str++;
    }
    return (word_count);
}

int ft_word_len(char *str)
{
    int word_len;

    word_len = 1;
    while (*str && !is_delim(*str))            
        word_len++;
    return (word_len);
}

void ft_strcpy(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i] && !is_delim(src[i]))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char **ft_split(char *str)
{
    char **strarr;
    char *word;

    strarr = malloc((ft_word_count(str) + 1) * sizeof(char*));
    while (*str)
    {
        word = malloc((ft_word_len(str) + 1) * sizeof(char));
        ft_strcpy(word, *strarr);
        strarr++;
        while (*str && !is_delim(*str))
            
        free(word);
    }
    return (strarr);
}

int main(int ac, char **av)
{
    char **strarr;

    char *str = " test tes1 t2.";

    if (ac == ac)
    {
        strarr = ft_split(str);
        for (int i = 0; i < ft_word_len(str); i++)
            printf("%s\n", strarr[i]);
    }
    printf("\n");
}