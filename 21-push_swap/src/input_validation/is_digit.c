#include "input_validation.h"


int is_number(char *str)
{
    if (*str == '\0' || str == NULL)
        return (0);
    if ((*str == '+') || (*str == '-'))
        str++;
    if (!ft_isdigit(*str))
        return (0);
    while (*str != '\0')
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}
