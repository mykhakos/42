#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;    
    write(fd, s, ft_strlen(s));
}

/*
int main()
{
    ft_putstr_fd("aaaaaaaaa", 1);
    return 0;
}
*/