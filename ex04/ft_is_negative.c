#include <unistd.h>

void ft_is_negative(int n)
{
    char res = 'P';

    if (n < 0)
    {
        res = 'N';
    }

    write(1, &res, 1);

}

int main(void)
{
    ft_is_negative(-2);
}