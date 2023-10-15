#include <stdio.h>
#include "include/pipex.h"



int count_len(char *arg, char sep)
{
    int len;

    len = 0;
    while (arg[len] != sep && arg[len] != '\0')
    {
        len++;
    }
    return (len);
}


int count_args(char *command_args)
{
    int count;
    char current_quote;
    int len;
    int inside_quote = 0;

    count = 0;
    while (*command_args != '\0') 
    {
        while (*command_args == ' ' && !inside_quote)
            command_args++;

        if (*command_args == '\'' || *command_args == '"') 
        {
            current_quote = *command_args;
            command_args++;  // Move past the opening quote

            len = count_len(command_args, current_quote);  // Now, count_len knows it's inside a quote

            count++;
            command_args += len;

            // If we have a matching quote, move past it
            if (*command_args == current_quote) 
            {
                command_args++;
            }
        } 
        else 
        {
            len = count_len(command_args, ' ');  // Here, count_len knows it's NOT inside a quote
            command_args += len;
            count++;
        }
    }
    return (count);
}



int main() 
{
    // Test cases
    char *test1 = "one two three";
    char *test2 = "'one two' three";
    char *test3 = "\"one   two\" three   four five six'";
    char *test3_1 = "\"one   two\" three   four'five six'";
    char *test4 = "'' '' ''";
    char *test5 = "unmatched'";
    char *test6 = "";

    printf("Test 1 (Expected 3): %d\n", count_args(test1));
    printf("Test 2 (Expected 2): %d\n", count_args(test2));
    printf("Test 3.1 (Expected 5): %d\n", count_args(test3));
    printf("Test 3.2 (Expected 3): %d\n", count_args(test3_1));
    printf("Test 4 (Expected 3): %d\n", count_args(test4));
    printf("Test 5 (Expected 1): %d\n", count_args(test5));
    printf("Test 6 (Expected 0): %d\n", count_args(test6));

    return 0;
}





