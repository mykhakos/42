#include <unistd.h>

void ft_reverse_print_alphabet(void)
{
    char letter = 'z';
    while(letter >= 'a')
    {
        write(1, &letter, 1);
        letter--;
    }
}

int main(void)
{
    ft_reverse_print_alphabet();
}